#***********************************************************************
#
#  Copyright (c) 2006  Broadcom Corporation
#  All Rights Reserved
#
# 
# 
# This program is free software; you can redistribute it and/or modify 
# it under the terms of the GNU General Public License, version 2, as published by  
# the Free Software Foundation (the "GPL"). 
# 
#
# 
# This program is distributed in the hope that it will be useful,  
# but WITHOUT ANY WARRANTY; without even the implied warranty of  
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
# GNU General Public License for more details. 
#  
# 
#  
#   
# 
# A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by 
# writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, 
# Boston, MA 02111-1307, USA. 
#
#
#***********************************************************************/

#
# To add an app, add it to APP_DIRS, and write the target rule in the
# last section of this Makefile
#
APP_DIRS = dhcpv6 ppp sshd ipsec-tools ledctl dhrystone tcpdump sendpackets

#
# We need to declare these directory names as phony targets,
# otherwise make will think the directories themselves are
# the targets and will never execute the cmds.
# See GNU Make, 4.6 
#
.PHONY : $(APP_DIRS)


# Some apps have names that are different from their directory
# name, so need to list them explictly here.
all : $(APP_DIRS) pppd


#
# Cleaning rules
# See example in GNU Make, 4.6
# (ppp does not have a top level Makefile, so we can't just cd into
# and do a make clean.  Remove ppp from APP_DIRS and write out
# an explicit rule.)
#
clean: 
	for dir in $(subst ppp,,$(APP_DIRS)); do \
		$(MAKE) -C $$dir clean; \
	done
	$(MAKE) -C ppp/pppoe clean
# << [CTFN-3G-001] MHTsai: Support 3G feature, 2010/08/09
	$(MAKE) -C ppp/pppd clean
# >> [CTFN-3G-001] End

#
# Set our CommEngine directory (by splitting the pwd into two words
# at /userspace and taking the first word only).
# Then include the common defines under CommEngine.
# You do not need to modify this part.
#
CURR_DIR := $(shell pwd)
BUILD_DIR:=$(subst /userspace, /userspace,$(CURR_DIR))
BUILD_DIR:=$(word 1, $(BUILD_DIR))

include $(BUILD_DIR)/make.common

ifneq ($(strip $(BUILD_VODSL)),)
include $(BUILD_DIR)/make.voice
endif

export BUILD_DIR
export CFLAGS


##############################################################
# 
# Rules for inidividual apps
# apps can be compiled or not depending on the profile (which
# is modified via make menuconfig)
#
##############################################################

ifneq ($(strip $(BUILD_SSHD)),)
sshd:
	(tar xkjf sshd.tar.bz2 2> /dev/null || true)
	$(MAKE) -C sshd
else
sshd:
	@echo "skipping sshd (not configured)"
endif

ifneq ($(strip $(BUILD_IPV6)),)
dhcpv6:
	(tar xkjf dhcpv6.tar.bz2 2> /dev/null || true)
	$(MAKE) -j1 -C dhcpv6
else
dhcpv6:
	@echo "skipping dhcpv6 (not configured)"
endif


ifneq ($(strip $(BUILD_PPPD)),)
pppd:
	$(MAKE) -C ppp/pppoe $(BUILD_PPPD)
# << [CTFN-3G-001] MHTsai: Support 3G feature, 2010/08/09
ifneq ($(strip $(CTCONFIG_3G_FEATURE)),)
	@echo "building 3G ppp"
	$(MAKE) -C ppp/chat clean
	$(MAKE) -C ppp/chat
	$(MAKE) -C ppp/chat install
	$(MAKE) -C ppp/pppd clean
	$(MAKE) -C ppp/pppd install
endif
# >> [CTFN-3G-001] End
else
pppd:
	@echo "skipping pppd (not configured)"
endif

ifneq ($(strip $(BUILD_IPSEC_TOOLS)),)
ipsec-tools:
	(tar xkjf ipsec-tools.tar.bz2 2> /dev/null || true)
	$(MAKE) -j1 -C ipsec-tools $(BUILD_IPSEC_TOOLS)
else
ipsec-tools:
	@echo "skipping ipsec-tools (not configured)"
endif

ifneq ($(strip $(BUILD_LEDCTL)),)
ledctl:
	$(MAKE) -C $@
else
ledctl:
	@echo "skipping $@ (not configured)"
endif

ifneq ($(strip $(BENCHMARKS_SMP)),)
dhrystone:
	$(MAKE) -C $@
else
dhrystone:
	@echo "skipping dhrystone (not configured)"
endif

ifneq ($(strip $(BUILD_SENDPACKETS)),)
sendpackets:
	$(MAKE) -C sendpackets install
else
sendpackets:
	@echo "skipping sendpackets (not configured)"
endif

ifneq ($(strip $(BUILD_TCPDUMP)),)
tcpdump:
	ln -sf tcpdump tcpdump-4.1.1
	(tar xkz  -f tcpdump.tar.gz 2> /dev/null || true)
	rm -f tcpdump-4.1.1
	$(MAKE) -C tcpdump install
else
tcpdump:
	@echo "skipping tcpdump (not configured)"
endif


