/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright (c) 2003  Marcus R. Brown <mrbrown@0xd6.org>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

/**
 * @file
 * rom0:SIO2MAN module definitions
 */

#ifndef SIO2MAN_H
#define SIO2MAN_H

struct _sio2_dma_arg { // size 12
	void	*addr;
	int	size;
	int	count;
};

typedef struct {
	u32	stat6c;

	u32	port_ctrl1[4];
	u32	port_ctrl2[4];

	u32	stat70;

	u32	regdata[16];

	u32	stat74;

	u32	in_size;
	u32	out_size;
	u8	*in;
	u8	*out;

	struct _sio2_dma_arg in_dma;
	struct _sio2_dma_arg out_dma;
} sio2_transfer_data_t;

#define sio2man_IMPORTS_start DECLARE_IMPORT_TABLE(sio2man, 1, 1)
#define sio2man_IMPORTS_end END_IMPORT_TABLE

void sio2_ctrl_set(u32 val);
#define I_sio2_ctrl_set DECLARE_IMPORT(4, sio2_ctrl_set)

u32 sio2_ctrl_get(void);
#define I_sio2_ctrl_get DECLARE_IMPORT(5, sio2_ctrl_get)

u32 sio2_stat6c_get(void);
#define I_sio2_stat6c_get DECLARE_IMPORT(6, sio2_stat6c_get)

void sio2_portN_ctrl1_set(int N, u32 val);
#define I_sio2_portN_ctrl1_set DECLARE_IMPORT(7, sio2_portN_ctrl1_set)

u32 sio2_portN_ctrl1_get(int N);
#define I_sio2_portN_ctrl1_get DECLARE_IMPORT(8, sio2_portN_ctrl1_get)

void sio2_portN_ctrl2_set(int N, u32 val);
#define I_sio2_portN_ctrl2_set DECLARE_IMPORT(9, sio2_portN_ctrl2_set)

u32 sio2_portN_ctrl2_get(int N);
#define I_sio2_portN_ctrl2_get DECLARE_IMPORT(10, sio2_portN_ctrl2_get)

u32 sio2_stat70_get(void);
#define I_sio2_stat70_get DECLARE_IMPORT(11, sio2_stat70_get)

void sio2_regN_set(int N, u32 val);
#define I_sio2_regN_set DECLARE_IMPORT(12, sio2_regN_set)

u32 sio2_regN_get(int N);
#define I_sio2_regN_get DECLARE_IMPORT(13, sio2_regN_get)

u32 sio2_stat74_get(void);
#define I_sio2_stat74_get DECLARE_IMPORT(14, sio2_stat74_get)

void sio2_unkn78_set(u32 val);
#define I_sio2_unkn78_set DECLARE_IMPORT(15, sio2_unkn78_set)

u32 sio2_unkn78_get(void);
#define I_sio2_unkn78_get DECLARE_IMPORT(16, sio2_unkn78_get)

void sio2_unkn7c_set(u32 val);
#define I_sio2_unkn7c_set DECLARE_IMPORT(17, sio2_unkn7c_set)

u32 sio2_unkn7c_get(void);
#define I_sio2_unkn7c_get DECLARE_IMPORT(18, sio2_unkn7c_get)

void sio2_data_out(u8 val);
#define I_sio2_data_out DECLARE_IMPORT(19, sio2_data_out)

u8 sio2_data_in(void);
#define I_sio2_data_in DECLARE_IMPORT(20, sio2_data_in)

void sio2_stat_set(u32 val);
#define I_sio2_stat_set DECLARE_IMPORT(21, sio2_stat_set)

u32 sio2_stat_get(void);
#define I_sio2_stat_get DECLARE_IMPORT(22, sio2_stat_get)

void sio2_pad_transfer_init(void);
#define I_sio2_pad_transfer_init DECLARE_IMPORT(23, sio2_pad_transfer_init)

void sio2_mc_transfer_init(void);
#define I_sio2_mc_transfer_init DECLARE_IMPORT(24, sio2_mc_transfer_init)

int sio2_transfer(sio2_transfer_data_t *td);
#define I_sio2_transfer DECLARE_IMPORT(25, sio2_transfer)

#endif /* SIO2MAN_H */
