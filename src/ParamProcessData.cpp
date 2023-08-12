#include"globals.h"

struct DATA process_data[] =
{
    //sts_wd_1
    ID_PDO_00,
    CTRL_OUTPUT,
    ID_PDO_00_BYTE,
    &sts_wd_1,

    //alm_wd_1
    ID_PDO_01,
    CTRL_OUTPUT,
    ID_PDO_01_BYTE,
    &alm_wd_1,

    //v_inv
    ID_PDO_02,
    ADC_OUTPUT,
    ID_PDO_02_BYTE,
    &adc.adc_ctrl_fdb.v_inv_f,

    //i_inv
    ID_PDO_03,
    ADC_OUTPUT,
    ID_PDO_03_BYTE,
    &adc.adc_ctrl_fdb.i_inv_f,

    //v_inv_rect
    ID_PDO_04,
    ADC_OUTPUT,
    ID_PDO_04_BYTE,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_f,

    //i_inv_rect
    ID_PDO_05,
    ADC_OUTPUT,
    ID_PDO_05_BYTE,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_f,

    //ntc1
    ID_PDO_06,
    ADC_OUTPUT,
    ID_PDO_06_BYTE,
    &adc.adc_sys.ntc1_f,

    //ntc2
    ID_PDO_07,
    ADC_OUTPUT,
    ID_PDO_07_BYTE,
    &adc.adc_sys.ntc2_f,

    //pot
    ID_PDO_08,
    ADC_OUTPUT,
    ID_PDO_08_BYTE,
    &adc.adc_sys.pot_f,

    //scr_cmd_alfa
    ID_PDO_09,
    SCR_OUTPUT,
    ID_PDO_09_BYTE,
    &scr_cmd_alfa,

    //igbt_actual_freq
    ID_PDO_10,
    IGBT_OUTPUT,
    ID_PDO_10_BYTE,
    &igbt_actual_freq,

    //main_fsm_loop_cnt
    ID_PDO_11,
    DGN_OUTPUT,
    ID_PDO_11_BYTE,
    &main_fsm_loop_cnt,

    //scr_synch_invalid_cnt
    ID_PDO_12,
    SCR_OUTPUT,
    ID_PDO_12_BYTE,
    &scr_synch_invalid_cnt,

    //scr_synch_freq
    ID_PDO_13,
    SCR_OUTPUT,
    ID_PDO_13_BYTE,
    &scr_synch_freq
};

struct DATA param_data[] =
{
    //cmd_wd1
    ID_SDO_00,
    CTRL_INPUT,
    ID_SDO_00_BYTE,
    &cmd_wd_1,

    //init_cnt_end
    ID_SDO_01,
    CTRL_INPUT,
    ID_SDO_01_BYTE,
    &init_cnt_end,

    //scr_synch_estim_cnt_end
    ID_SDO_02,
    CTRL_INPUT,
    ID_SDO_02_BYTE,
    &scr_synch_estim_cnt_end,

    //en_manual_alfa
    ID_SDO_03,
    SCR_SETTINGS,
    ID_SDO_03_BYTE,
    &en_manual_alfa,

    //scr_cmd_alfa_set
    ID_SDO_04,
    SCR_SETTINGS,
    ID_SDO_04_BYTE,
    &scr_cmd_alfa_set,

    //scr_cmd_alfa_check_50hz
    ID_SDO_05,
    SCR_SETTINGS,
    ID_SDO_05_BYTE,
    &scr_cmd_alfa_check_50hz,

    //scr_cmd_alfa_check_60hz
    ID_SDO_06,
    SCR_SETTINGS,
    ID_SDO_06_BYTE,
    &scr_cmd_alfa_check_60hz,

    //freeze_scr_ramp_cnt_end
    ID_SDO_07,
    SCR_SETTINGS,
    ID_SDO_07_BYTE,
    &freeze_scr_ramp_cnt_end,

    //scr_cmd_alfa_increment
    ID_SDO_08,
    SCR_SETTINGS,
    ID_SDO_08_BYTE,
    &scr_cmd_alfa_increment,

    //igbt_main_freq
    ID_SDO_09,
    IGBT_SETTINGS,
    ID_SDO_09_BYTE,
    &igbt_main_freq,

    //sweep_amplitude
    ID_SDO_10,
    IGBT_SETTINGS,
    ID_SDO_10_BYTE,
    &sweep_amplitude,

    //sweep_freq
    ID_SDO_11,
    IGBT_SETTINGS,
    ID_SDO_11_BYTE,
    &sweep_freq,

    //v_inv_rect_gain
    ID_SDO_12,
    ADC_SETTINGS,
    ID_SDO_12_BYTE,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_gain,

    //v_inv_rect_offset
    ID_SDO_13,
    ADC_SETTINGS,
    ID_SDO_13_BYTE,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_offset,

    //i_inv_rect_gain
    ID_SDO_14,
    ADC_SETTINGS,
    ID_SDO_14_BYTE,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_gain,

    //i_inv_rect_offset
    ID_SDO_15,
    ADC_SETTINGS,
    ID_SDO_15_BYTE,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_offset,

    //ntc1_gain
    ID_SDO_16,
    ADC_SETTINGS,
    ID_SDO_16_BYTE,
    &adc.adc_sys.ntc1_gain,

    //ntc1_offset
    ID_SDO_17,
    ADC_SETTINGS,
    ID_SDO_17_BYTE,
    &adc.adc_sys.ntc1_offset,

    //ntc2_gain
    ID_SDO_18,
    ADC_SETTINGS,
    ID_SDO_18_BYTE,
    &adc.adc_sys.ntc2_gain,

    //ntc2_offset
    ID_SDO_19,
    ADC_SETTINGS,
    ID_SDO_19_BYTE,
    &adc.adc_sys.ntc2_offset,

    //pot_gain
    ID_SDO_20,
    ADC_SETTINGS,
    ID_SDO_20_BYTE,
    &adc.adc_sys.pot_gain,

    //pot_offset
    ID_SDO_21,
    ADC_SETTINGS,
    ID_SDO_21_BYTE,
    &adc.adc_sys.pot_offset,

    //i_inv_oc
    ID_SDO_22,
    PROTECTION,
    ID_SDO_22_BYTE,
    &i_inv_oc,

    //en_sweep
    ID_SDO_23,
    IGBT_SETTINGS,
    ID_SDO_23_BYTE,
    &en_sweep,

    //scr_cmd_alfa_max
    ID_SDO_24,
    SCR_SETTINGS,
    ID_SDO_24_BYTE,
    &scr_cmd_alfa_max,

    //en_prot_overcurr
    ID_SDO_25,
    PROTECTION,
    ID_SDO_25_BYTE,
    &en_prot_overcurr
};