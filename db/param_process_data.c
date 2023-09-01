//########################################################################
//  Project     :   launch_f280039c_template                              
//  Target      :                                                         
//------------------------------------------------------------------------
//  Filename    :   param_process_data.c                                  
//  Author      :   lucag                                                 
//  Date        :   2023 9 1                                        
//------------------------------------------------------------------------
//  History     :                                                         
//  23 Aug 2023     - Creation                                            
//                                                                        
//------------------------------------------------------------------------
//!  Description:    DB_IKE_00.00.01                                    
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
    4.398322,
    0.227359,
    &cmd_in.init_time_ms,
    100,
    15000,

    //durata fase misura frequenza,
    2,
    CTRL_INPUT,
    uint,
    &mb.holdingRegisters.dummy2,
    4.398322,
    0.227359,
    &cmd_in.freq_estim_time_ms,
    100,
    15000,

    //abilita settaggio manuale apertura scr,
    3,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy3,
    65535,
    0.000015,
    &scr.en_manual_alfa,
    0,
    1,

    //valore settaggio manuale apertura scr,
    4,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy4,
    182.046724,
    0.005493,
    &scr.scr_cmd_alfa_set,
    0,
    359.990000,

    //valore apertura scr durante il check a 50Hz,
    5,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy5,
    182.046724,
    0.005493,
    &scr.scr_cmd_alfa_check_50hz,
    0,
    359.990000,

    //valore apertura scr durante il check a 60Hz,
    6,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy6,
    182.046724,
    0.005493,
    &scr.scr_cmd_alfa_check_60hz,
    0,
    359.990000,

    //durata apertura scr ridotta per check,
    7,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy7,
    1,
    1,
    &scr.freeze_scr_ramp_time_ms,
    0,
    65535,

    //tempo per la rampa scr,
    8,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy8,
    1,
    1,
    &scr.scr_ramp_time_ms,
    0,
    65535,

    //frequenza principale igbt,
    9,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy9,
    4369,
    0.000229,
    &igbt.igbt_main_freq,
    15,
    30,

    //range modulante sinusoidale sweep igbt,
    10,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy10,
    3276.750000,
    0.000305,
    &igbt.sweep_amplitude,
    0,
    20,

    //frequenza modulante sinusoidale sweep igbt,
    11,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy11,
    655.350000,
    0.001526,
    &igbt.sweep_freq,
    0,
    100,

    //abilita sweep igbt,
    12,
    IGBT_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy12,
    65535,
    0.000015,
    &igbt.en_sweep,
    0,
    1,

    //adattamento adc v_inv_rect_gain,
    13,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy13,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_gain,
    0,
    1000,

    //adattamento adc v_inv_rect_offset,
    14,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy14,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_offset,
    -500,
    500,

    //adattamento adc i_inv_rect_gain,
    15,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy15,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_gain,
    0,
    1000,

    //adattamento adc i_inv_rect_offset,
    16,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy16,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_offset,
    -500,
    500,

    //adattamento adc ntc1_gain,
    17,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy17,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc1_gain,
    0,
    1000,

    //adattamento adc ntc1_offset,
    18,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy18,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc1_offset,
    -500,
    500,

    //adattamento adc ntc2_gain,
    19,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy19,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc2_gain,
    0,
    1000,

    //adattamento adc ntc2_offset,
    20,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy20,
    65.535000,
    0.015259,
    &adc.adc_sys.ntc2_offset,
    -500,
    500,

    //adattamento adc pot_gain,
    21,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy21,
    65.535000,
    0.015259,
    &adc.adc_sys.pot_gain,
    0,
    1000,

    //adattamento adc pot_offset,
    22,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy22,
    65.535000,
    0.015259,
    &adc.adc_sys.pot_offset,
    -500,
    500,

    //valore di scatto sovracorrente AC,
    23,
    PROTECTION,
    real,
    &mb.holdingRegisters.dummy23,
    6553.500000,
    0.000153,
    &protection.i_inv_oc,
    0,
    10
};                                                                        
                                                                          
struct DATA process_data[] =                                              
{                                                                         
    //word stato 1,
    24,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy24,
    1,
    1,
    &sts_out.sts_wd_1,
    0,
    65535,

    //word allarme 1,
    25,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy25,
    1,
    1,
    &sts_out.alm_wd_1,
    0,
    65535,

    //tensione uscita (rms),
    26,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy26,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb.v_inv_f,
    0,
    600,

    //corrente uscita (rms),
    27,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy27,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb.i_inv_f,
    0,
    50,

    //tensione uscita (rettificata),
    28,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy28,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_f,
    0,
    600,

    //corrente uscita (rettificata),
    29,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy29,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_f,
    0,
    50,

    //temperatura ntc1,
    30,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy30,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc1_f,
    -20,
    180,

    //temperatura ntc2,
    31,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy31,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc2_f,
    -20,
    180,

    //valore potenziometro,
    32,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy32,
    65535,
    0.000015,
    &adc.adc_sys.pot_f,
    0,
    1,

    //apertura scr,
    33,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy33,
    182.046724,
    0.005493,
    &scr.cmd_alfa,
    0,
    359.990000,

    //frequenza attuale igbt,
    34,
    IGBT_OUTPUT,
    real,
    &mb.holdingRegisters.dummy34,
    1310.700000,
    0.000763,
    &igbt.igbt_actual_freq,
    0,
    50,

    //contatore isr timer 0,
    35,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy35,
    1,
    1,
    &diagn_out.main_fsm_loop_time_ms,
    0,
    65535,

    //numero conteggi invalidi misura frequenza,
    36,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy36,
    1,
    1,
    &diagn_out.scr_synch_invalid_cnt,
    0,
    65535,

    //inverter datetime - seconds,
    37,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy37,
    1,
    1,
    &diagn_out.datetime.Second,
    0,
    65535,

    //inverter datetime - minutes,
    38,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy38,
    1,
    1,
    &diagn_out.datetime.Minute,
    0,
    65535,

    //inverter datetime - hours,
    39,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy39,
    1,
    1,
    &diagn_out.datetime.Hour,
    0,
    65535,

    //inverter datetime - day,
    40,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy40,
    1,
    1,
    &diagn_out.datetime.Day,
    0,
    65535,

    //inverter datetime - day of week,
    41,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy41,
    1,
    1,
    &diagn_out.datetime.DayOfWeek,
    0,
    65535,

    //inverter datetime - month,
    42,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy42,
    1,
    1,
    &diagn_out.datetime.Month,
    0,
    65535,

    //inverter datetime - year,
    43,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy43,
    1,
    1,
    &diagn_out.datetime.Year,
    0,
    65535,

    //versione firmware - H1.H2.L1.L2.TYPE,
    44,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy44,
    1,
    1,
    &diagn_out.fmw_version,
    0,
    65535,

    //frequenza attuale ingresso,
    45,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy45,
    1008.230769,
    0.000992,
    &scr.scr_synch_freq,
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
