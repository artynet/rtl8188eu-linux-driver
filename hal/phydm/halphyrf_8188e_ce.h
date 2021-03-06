/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2007 - 2016 Realtek Corporation. All rights reserved. */


#ifndef __HAL_PHY_RF_8188E_H__
#define __HAL_PHY_RF_8188E_H__

/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_88E		10		/* ms */
#define	index_mapping_NUM_88E	15
#define AVG_THERMAL_NUM_88E	4

#include "halphyrf_ce.h"

void configure_txpower_track_8188e(
	struct _TXPWRTRACK_CFG	*p_config
);

void
get_delta_swing_table_8188e(
	void		*p_dm_void,
	u8 **temperature_up_a,
	u8 **temperature_down_a,
	u8 **temperature_up_b,
	u8 **temperature_down_b
);

void do_iqk_8188e(
	void		*p_dm_void,
	u8		delta_thermal_index,
	u8		thermal_value,
	u8		threshold
);

void
odm_tx_pwr_track_set_pwr88_e(
	void		*p_dm_void,
	enum pwrtrack_method	method,
	u8				rf_path,
	u8				channel_mapped_index
);

/* 1 7.	IQK */

void
phy_iq_calibrate_8188e(
	struct _ADAPTER	*adapter,
	bool	is_recovery);

/*
 * LC calibrate
 *   */
void
phy_lc_calibrate_8188e(
	void		*p_dm_void
);

void
phy_digital_predistortion_8188e(struct _ADAPTER	*p_adapter);


void
_phy_save_adda_registers(
	struct _ADAPTER	*p_adapter,
	u32		*adda_reg,
	u32		*adda_backup,
	u32		register_num
);

void
_phy_path_adda_on(
	struct _ADAPTER	*p_adapter,
	u32		*adda_reg,
	bool		is_path_a_on,
	bool		is2T
);

void
_phy_mac_setting_calibration(
	struct _ADAPTER	*p_adapter,
	u32		*mac_reg,
	u32		*mac_backup
);


void
_phy_path_a_stand_by(
	struct _ADAPTER	*p_adapter
);


#endif	/*  #ifndef __HAL_PHY_RF_8188E_H__ */
