//########################################################################
//  Project     :   launch_f280039c_template                              
//  Target      :                                                         
//------------------------------------------------------------------------
//  Filename    :   param_process_data.c                                  
//  Author      :   lucag                                                 
//  Date        :   2023 9 25                                        
//------------------------------------------------------------------------
//  History     :                                                         
//  23 Aug 2023     - Creation                                            
//                                                                        
//------------------------------------------------------------------------
//!  Description:    02.03.01                                    
//!                                                                       
//                                                                        
//########################################################################
                                                                          
/* ## Defines ######################################################### */
                                                                          
/* ## Header Includes ################################################# */
                                                                          
#include "param_process_data.h"                                         
#include "globals.h"                                                    
#if MB_LIBMODBUS_TESTS == false                                           
#include "modbus_rtu/ModbusDataMap.h"                                   
#else                                                                     
#include "modbus_rtu/ModbusDataMapTests.h"                              
#endif                                                                    
                                                                          
/* ## Local Vars ###################################################### */
                                                                          
struct DATA params_data[] =                                               
{                                                                         
    //word comando 1,
    0,
    CTRL_INPUT,
    word,
    &mb.holdingRegisters.dummy0,
    1,
    1,
    &cmd_in.cmd_wd_1,
    0,
    65535,

    //durata fase init,
    1,
    CTRL_INPUT,
    uint,
    &mb.holdingRegisters.dummy1,
    10.000763,
    0.099992,
    &cmd_in.init_time_ms,
    0,
    6553,

    //durata fase misura frequenza,
    2,
    CTRL_INPUT,
    uint,
    &mb.holdingRegisters.dummy2,
    43.983221,
    0.022736,
    &cmd_in.freq_estim_time_ms,
    10,
    1500,

    //abilita settaggio manuale apertura scr,
    3,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy3,
    1,
    1,
    &scr_sett.en_manual_alfa,
    0,
    65535,

    //valore settaggio manuale apertura scr,
    4,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy4,
    65535,
    0.000015,
    &scr_sett.scr_cmd_alfa_set,
    0,
    1,

    //valore apertura scr durante il check a 50Hz,
    5,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy5,
    65535,
    0.000015,
    &scr_sett.scr_cmd_alfa_check_50hz,
    0,
    1,

    //valore apertura scr durante il check a 60Hz,
    6,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy6,
    65535,
    0.000015,
    &scr_sett.scr_cmd_alfa_check_60hz,
    0,
    1,

    //durata apertura scr ridotta per check,
    7,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy7,
    10.000763,
    0.099992,
    &scr_sett.scr_freeze_ramp_cnt_end,
    0,
    6553,

    //tempo per la rampa scr,
    8,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy8,
    10.000763,
    0.099992,
    &scr_sett.scr_ramp_time_cnt_end,
    0,
    6553,

    //abilita sweep igbt,
    9,
    IGBT_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy9,
    1,
    1,
    &igbt_sett.en_sweep,
    0,
    65535,

    //frequenza principale igbt,
    10,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy10,
    4.369000,
    0.228885,
    &igbt_sett.igbt_main_freq,
    15000,
    30000,

    //range modulante sinusoidale sweep igbt,
    11,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy11,
    3.276750,
    0.305180,
    &igbt_sett.sweep_amplitude,
    0,
    20000,

    //frequenza modulante sinusoidale sweep igbt,
    12,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy12,
    655.350000,
    0.001526,
    &igbt_sett.sweep_freq,
    0,
    100,

    //durata senza sweep igbt per check,
    13,
    IGBT_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy13,
    10.000763,
    0.099992,
    &igbt_sett.freeze_sweep_cnt_end,
    0,
    6553,

    //adattamento adc v_inv_rect_gain,
    14,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy14,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_gain,
    0,
    1000,

    //adattamento adc v_inv_rect_offset,
    15,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy15,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_offset,
    -500,
    500,

    //adattamento adc i_inv_rect_gain,
    16,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy16,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_gain,
    0,
    1000,

    //adattamento adc i_inv_rect_offset,
    17,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy17,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_offset,
    -500,
    500,

    //adattamento adc ntc1_gain,
    18,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy18,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc1_gain,
    0,
    1000,

    //adattamento adc ntc1_offset,
    19,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy19,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc1_offset,
    -500,
    500,

    //adattamento adc ntc2_gain,
    20,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy20,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc2_gain,
    0,
    1000,

    //adattamento adc ntc2_offset,
    21,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy21,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc2_offset,
    -500,
    500,

    //adattamento adc pot_gain,
    22,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy22,
    65.535000,
    0.015259,
    &adc.adc_sys.pot_gain,
    0,
    1000,

    //adattamento adc pot_offset,
    23,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy23,
    65.535000,
    0.015259,
    &adc.adc_sys.pot_offset,
    -500,
    500,

    //valore di scatto sovracorrente AC,
    24,
    PROTECTION,
    real,
    &mb.holdingRegisters.dummy24,
    6553.500000,
    0.000153,
    &protection.i_inv_oc,
    0,
    10
};                                                                        
                                                                          
struct DATA process_data[] =                                              
{                                                                         
    //word stato 1,
    25,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy25,
    1,
    1,
    &sts_out.sts_wd_1,
    0,
    65535,

    //word allarme 1,
    26,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy26,
    1,
    1,
    &sts_out.alm_wd_1,
    0,
    65535,

    //tensione uscita (rms),
    27,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy27,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb.v_inv_f,
    0,
    600,

    //corrente uscita (rms),
    28,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy28,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb.i_inv_f,
    0,
    50,

    //tensione uscita (rettificata),
    29,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy29,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_f,
    0,
    600,

    //corrente uscita (rettificata),
    30,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy30,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_f,
    0,
    50,

    //temperatura ntc1,
    31,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy31,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc1_f,
    -20,
    180,

    //temperatura ntc2,
    32,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy32,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc2_f,
    -20,
    180,

    //valore potenziometro,
    33,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy33,
    655.350000,
    0.001526,
    &adc.adc_sys.pot_f,
    0,
    100,

    //frequenza attuale igbt,
    34,
    IGBT_OUTPUT,
    real,
    &mb.holdingRegisters.dummy34,
    1.310700,
    0.762951,
    &igbt_out.igbt_actual_freq,
    0,
    50000,

    //tempo freeze sweep igbt,
    35,
    IGBT_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy35,
    10.000763,
    0.099992,
    &igbt_out.freeze_sweep_cnt_ms,
    0,
    6553,

    //contatore isr timer 0,
    36,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy36,
    10.000763,
    0.099992,
    &diagn_out.main_fsm_loop_time_ms,
    0,
    6553,

    //numero conteggi invalidi misura frequenza,
    37,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy37,
    1,
    1,
    &diagn_out.scr_synch_invalid_cnt,
    0,
    65535,

    //inverter datetime - seconds,
    38,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy38,
    1,
    1,
    &diagn_out.datetime.Second,
    0,
    65535,

    //inverter datetime - minutes,
    39,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy39,
    1,
    1,
    &diagn_out.datetime.Minute,
    0,
    65535,

    //inverter datetime - hours,
    40,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy40,
    1,
    1,
    &diagn_out.datetime.Hour,
    0,
    65535,

    //inverter datetime - day,
    41,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy41,
    1,
    1,
    &diagn_out.datetime.Day,
    0,
    65535,

    //inverter datetime - day of week,
    42,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy42,
    1,
    1,
    &diagn_out.datetime.DayOfWeek,
    0,
    65535,

    //inverter datetime - month,
    43,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy43,
    1,
    1,
    &diagn_out.datetime.Month,
    0,
    65535,

    //inverter datetime - year,
    44,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy44,
    1,
    1,
    &diagn_out.datetime.Year,
    0,
    65535,

    //versione firmware - H.L.TYPE,
    45,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy45,
    1,
    1,
    &diagn_out.fmw_version,
    0,
    65535,

    //versione database - DB_IKE_H.L1.L2,
    46,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy46,
    1,
    1,
    &diagn_out.db_version,
    0,
    65535,

    //apertura scr,
    47,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy47,
    65535,
    0.000015,
    &scr_out.scr_cmd_alfa,
    0,
    1,

    //frequenza attuale ingresso,
    48,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy48,
    1008.230769,
    0.000992,
    &scr_out.scr_synch_freq,
    0,
    65
};                                                                        
                                                                          
/* #################################################################### */
/* ############################# CODE ################################# */
                                                                          
void updateParamsDataIn()                                                 
{                                                                         
    Uint16 i;                                                             
    for (i = 0; i < PARAMS_LENGTH; i++)                                   
    {                                                                     
        switch (params_data[i].type)                                      
        {                                                                 
        case word:                                                        
        case uint:                                                        
            *(unsigned int*)params_data[i].val =                          
                ((*params_data[i].val_modbus *                            
                params_data[i].k_u16_to_double) +                         
                __f32toui16r(params_data[i].lim_min));                    
            break;                                                        
        case real:                                                        
            *(float*)params_data[i].val =                                 
                ((*params_data[i].val_modbus *                            
                params_data[i].k_u16_to_double) +                         
                params_data[i].lim_min);                                  
            break;                                                        
        }                                                                 
    }                                                                     
}                                                                         
                                                                          
void updateProcessDataOut()                                               
{                                                                         
    Uint16 i;                                                             
                                                                          
    for (i = 0; i < PROCESS_LENGTH; i++)                                  
    {                                                                     
        switch (process_data[i].type)                                     
        {                                                                 
        case word:                                                        
        case uint:                                                        
            *process_data[i].val_modbus =                                 
                (*(unsigned int*)process_data[i].val -                    
                __f32toui16r(process_data[i].lim_min))*                   
                process_data[i].k_double_to_u16;                          
            break;                                                        
        case real:                                                        
            *process_data[i].val_modbus =                                 
                (*(float*)process_data[i].val -                           
                process_data[i].lim_min)*                                 
                process_data[i].k_double_to_u16;                          
            break;                                                        
        }                                                                 
    }                                                                     
}                                                                         
                                                                          
/* #################################################################### */
/* #################################################################### */
