/*
 * $Id: types.h,v 1.61.2.11 Broadcom SDK $
 *
 * $Copyright: Copyright 2008 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.
 *
 * Except as expressly set forth in the Authorized License,
 *
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 *
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#ifndef __BCM_SWAPI_TYPES_H__
#define __BCM_SWAPI_TYPES_H__

//#include <bcmtypes.h>

/*
 * BCM API error codes.
 *
 * Note: An error code may be converted to a string by passing the code
 * to bcm_errmsg().
 */
typedef enum bcm_error_e {
  BCM_E_NONE = 0,
  BCM_E_INTERNAL,
  BCM_E_MEMORY,
  BCM_E_UNIT,
  BCM_E_PARAM,
  BCM_E_EMPTY,
  BCM_E_FULL,
  BCM_E_NOT_FOUND,
  BCM_E_EXISTS,
  BCM_E_TIMEOUT,
  BCM_E_BUSY,
  BCM_E_FAIL,
  BCM_E_DISABLED,
  BCM_E_BADID,
  BCM_E_RESOURCE,
  BCM_E_CONFIG,
  BCM_E_UNAVAIL,
  BCM_E_INIT,
  BCM_E_PORT
} bcm_error_t;

typedef int bcm_port_t;

/* bcm_vlan_t */
typedef unsigned short bcm_vlan_t;

/* bcm_vlan_tag_t */
typedef unsigned int bcm_vlan_tag_t;

/* bcm_cos_t */
typedef int bcm_cos_t;

/* bcm_cos_queue_t */
typedef int bcm_cos_queue_t;

/* Various operations through the SIOCETHSWCTLOPS */
enum {
    ETHSWDUMPPAGE = 0,
    ETHSWDUMPIUDMA,
    ETHSWIUDMASPLIT,
    ETHSWDUMPMIB,
    ETHSWSWITCHING,
    ETHSWRXSCHEDULING,
    ETHSWWRRPARAM,
    ETHSWUSEDEFTXQ,
    ETHSWDEFTXQ,
    ETHSWRXRATECFG,
    ETHSWRXRATELIMITCFG,
    ETHSWRXPKTRATECFG,
    ETHSWRXPKTRATELIMITCFG,
    ETHSWCONTROL,
    ETHSWPRIOCONTROL,
    ETHSWPORTTAGREPLACE,
    ETHSWPORTTAGMANGLE,
    ETHSWPORTTAGMANGLEMATCHVID,
    ETHSWPORTTAGSTRIP,
    ETHSWPORTPAUSECAPABILITY,
    ETHSWVLAN,
    ETHSWGETRXCOUNTERS,
    ETHSWRESETRXCOUNTERS,
    ETHSWPBVLAN,
    ETHSWCOSCONF,
    ETHSWCOSSCHED,
    ETHSWCOSPORTMAP,
    ETHSWCOSRXCHMAP,
    ETHSWCOSTXCHMAP,
    ETHSWCOSTXQSEL,
    ETHSWSTATCLR,
    ETHSWSTATPORTCLR,
    ETHSWSTATSYNC,
    ETHSWSTATGET,
    ETHSWPORTRXRATE,
    ETHSWPORTTXRATE,
    ETHSWTEST1,
    ETHSWARLACCESS,
    ETHSWPORTDEFTAG,
    ETHSWCOSPRIORITYMETHOD,
    ETHSWREGACCESS,
    ETHSWSPIACCESS,
    ETHSWPSEUDOMDIOACCESS,
    ETHSWINFO,
    ETHSWLINKSTATUS,
    ETHSWPORTTRAFFICCTRL,
    ETHSWPORTLOOPBACK,
    ETHSWPHYMODE,
    ETHSWPKTPAD,
    ETHSWJUMBO,
    ETHSWCOSDSCPPRIOMAP,
    ETHSWKERNELPOLL,
    ETHSWPHYCFG,
    ETHSWMOCASOFTSWITCH, 
    ETHSWSOFTSWITCHSTARTQ,
    ETHSWMOCAXMITBUDGET,
    ETHSWMOCAPORTCHECK
};

#if defined(CONFIG_BCM96816) || defined(CHIP_6816)
#define BCM_COS_COUNT  8
#else
#define BCM_COS_COUNT  4
#endif

struct ethswctl_data {
    /* ethswctl ioctl operation */
    int op;
    /* page number */
    int page;
    /* switch unit number */
    int unit;
    /* switch port number */
    int port;
    /* dump subset or all; or indicates enable/disable/get op */
    int type;
#define TYPE_SUBSET  0
#define TYPE_ALL     1
#define TYPE_DISABLE 0
#define TYPE_ENABLE  1
#define TYPE_GET     2
#define TYPE_SET     3
#define TYPE_DUMP    4
#define TYPE_FLUSH   5
    int sub_type;
#define SUBTYPE_ISRCFG      0
#define SUBTYPE_RXDUMP      1
#define SUBTYPE_RESETMIB    2
#define SUBTYPE_RESETSWITCH 3
    /* hardware switching enable/disable status */
    int status;
#define STATUS_DISABLED 0
#define STATUS_ENABLED  1
    int vlan_tag;
    int vlan_param;
    int replace_type;
/* Defines for indicating the parameter in tag replace register */
#define  REPLACE_VLAN_TAG    0
#define  REPLACE_VLAN_TPID   1
#define  REPLACE_VLAN_TCI    2
#define  REPLACE_VLAN_VID    3
#define  REPLACE_VLAN_8021P  4
#define  REPLACE_VLAN_CFI  5
    int op_map;
    int ret_val;
    int val;
    int max_pkts_per_iter;
    int weights[BCM_COS_COUNT];
    int priority;
    int sw_ctrl_type;
    /* scheduling value for ETHSETSCHEDULING */
    int scheduling;
    int vid;
    unsigned char mac[6];
    unsigned char data[8];
    int chip_id;
    int spi_id;
    int bus_num;
    int fwd_map;
    int untag_map;
    int queue;
    int channel;
    int numq;
    unsigned long limit;
    unsigned long burst_size;
    unsigned long long counter_val;
    unsigned int vendor_id;
    unsigned int dev_id;
    unsigned int rev_id;
    int counter_type;
    unsigned int offset;
    int length;
    int speed;
    int duplex;
    unsigned int port_map;
    unsigned int phy_portmap;
	int phycfg;
	int epon_port;
};

/* Defines for set/get of various fields in VLAN TAG */
#define BCM_NET_VLAN_TPID_S        16
#define BCM_NET_VLAN_TPID_M        0xFFFF
#define BCM_NET_VLAN_VID_S         0
#define BCM_NET_VLAN_VID_M       0xFFF
#define BCM_NET_VLAN_TCI_S         0
#define BCM_NET_VLAN_TCI_M       0xFFFF
#define BCM_NET_VLAN_8021P_S       13
#define BCM_NET_VLAN_8021P_M       0x7
#define BCM_NET_VLAN_CFI_S         12
#define BCM_NET_VLAN_CFI_M         0x1

#define VLAN_FWD_MAP_M   0x1FF
#define VLAN_UNTAG_MAP_M 0x1FF
#define VLAN_UNTAG_MAP_S 9

/* Switch controls for sw_ctrl_type */
typedef enum bcm_switch_control_e {
  bcmSwitchBufferControl,       /* Enable/Disable Total/TxQ Pause/Drop */
  bcmSwitch8021QControl,          /* Enable/Disable 802.1Q */
  bcmSwitchTotalDropThreshold,    /* Configure Total Drop Threshold */
  bcmSwitchTotalPauseThreshold,   /* Configure Total Pause Threshold */
  bcmSwitchTotalHysteresisThreshold,  /* Configure Total Hysteresis Threshold */
  bcmSwitchTxQHiDropThreshold,    /* Configure TxQ Hi Drop Threshold */
  bcmSwitchTxQHiPauseThreshold,   /* Configure TxQ Hi Pause Threshold */
  bcmSwitchTxQHiHysteresisThreshold,  /* Configure TxQ Hi Hysteresis Threshold */
  bcmSwitchTxQLowDropThreshold,   /* Configure TxQ LOW Drop Threshold */
  bcmSwitch__Count
} bcm_switch_control_t;


/* For bcmSwitchBufferControl */
#define BCM_SWITCH_TXQ_PAUSE     0x1      /* Enable/Disable TXQ DROP. */
#define BCM_SWITCH_TXQ_DROP      0x2      /* Enable/Disable TXQ PAUSE. */
#define BCM_SWITCH_TOTAL_PAUSE     0x4      /* Enable/Disable TOTAL DROP. */
#define BCM_SWITCH_TOTAL_DROP    0x8      /* Enable/Disable TOTAL PAUSE. */

/* Defines for the op_map in tag_mangle_set/get */
#define BCM_PORT_REPLACE_TPID    0x8000  /* Replace TPID */
#define BCM_PORT_REPLACE_8021P     0x4000  /* Replace 802.1p bits */
#define BCM_PORT_REPLACE_CFI     0x2000  /* Replace CFI bit */
#define BCM_PORT_REPLACE_VID     0x1000  /* Replace VLAN ID */
#define BCM_PORT_TAG_MANGLE_OP_MAP_M 0xF000  /* Mask for all tag mangling ops */


/*  For scheduling mechanism selection */
#define SP_SCHEDULING  0
#define WRR_SCHEDULING 1
#define FAP_SCHEDULING 2
#define BCM_COSQ_STRICT  0
#define BCM_COSQ_WRR     1
#define BCM_COSQ_COMBO   2

#if defined(CONFIG_BCM96816) || defined(CHIP_6816)
#define NUM_EGRESS_QUEUES  8
#else
#define NUM_EGRESS_QUEUES  4
#endif

#define QOS_PAUSE_DROP_EN_MAP 0xF
#define MAX_PRIORITY_VALUE    7

/* Return Value Definitions */
#define BCM_E_ERROR  1

/* For pause_capability set/get functions */
#define PAUSE_FLOW_CTRL_NONE 0
#define PAUSE_FLOW_CTRL_AUTO 1
#define PAUSE_FLOW_CTRL_BOTH 2
#define PAUSE_FLOW_CTRL_TX   3
#define PAUSE_FLOW_CTRL_RX   4


/* For ETHSWCOSTXQSEL */
/* Use Tx BD priority for egress queue selection */
#define USE_TX_BD_PRIORITY  0
/* Use Tx iuDMA channel for egress queue selection */
#define USE_TX_DMA_CHANNEL  1
/* Indicates neither BD nor channel is used for queue selection*/
#define NONE_OF_THE_METHODS 0xFF

#define PORT_QOS      0
#define MAC_QOS       1
#define IEEE8021P_QOS 2
#define DIFFSERV_QOS  3
#define COMBO_QOS     4

#define PORT_RXDISABLE 0x1
#define PORT_TXDISABLE 0x2

#define MBUS_PCI     0
#define MBUS_SPI     1
#define MBUS_MDIO    2
#define MBUS_UBUS    3
#define MBUS_HS_SPI  4
#define MBUS_NONE    -1

#if 0
/* Phy config info embedded into phy_id of ETHERNET_SW_INFO */
/* TBD: How to share this info b/w boardparms.c and userspace app swmdk */
#define PHYCFG_VALID_M      1 
#define PHYCFG_VALID_S      31 
#define PHY_LNK_CFG_M       0x7
#define PHY_LNK_CFG_S       8
#define ATONEG_FOR_LINK     (0 << PHY_LNK_CFG_S)
#define FORCE_LINK_DOWN     (1 << PHY_LNK_CFG_S)
#define FORCE_LINK_10HD     (2 << PHY_LNK_CFG_S)
#define FORCE_LINK_10FD     (3 << PHY_LNK_CFG_S)
#define FORCE_LINK_100HD    (4 << PHY_LNK_CFG_S)
#define FORCE_LINK_100FD    (5 << PHY_LNK_CFG_S)
#define PHY_ADV_CAP_CFG_M   0x7
#define PHY_ADV_CAP_CFG_S   11
#define ADVERTISE_10HD      (0 << PHY_LNK_CFG_S)
#define ADVERTISE_10FD      (1 << PHY_LNK_CFG_S)
#define ADVERTISE_100HD     (2 << PHY_LNK_CFG_S)
#define ADVERTISE_100FD     (3 << PHY_LNK_CFG_S)
#define ADVERTISE_1000HD    (4 << PHY_LNK_CFG_S)
#define ADVERTISE_1000FD    (5 << PHY_LNK_CFG_S)
#define PHY_INTEGRATED_M    0x1
#define PHY_INTEGRATED_S    14
#define PHY_INTERNAL        (0 << PHY_INTEGRATED_S)
#define PHY_EXTERNAL        (1 << PHY_INTEGRATED_S)
#define MAC_PHY_IFACE_M     0x1
#define MAC_PHY_IFACE_S     15
#define MAC_PHY_IF_GMII_MII (0 << MAC_PHY_IFACE_S)     
#define MAC_PHY_IF_RGMII    (1 << MAC_PHY_IFACE_S)      
#define PHYID_LSBYTE_M      0xFF
#endif

#endif /* __BCM_SWAPI_TYPES_H__ */
