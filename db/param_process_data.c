//########################################################################
//  Project     :   launch_f280039c_template                              
//  Target      :                                                         
//------------------------------------------------------------------------
//  Filename    :   param_process_data.c                                  
//  Author      :   lucag                                                 
//  Date        :   2023 12 30                                        
//------------------------------------------------------------------------
//  History     :                                                         
//  23 Aug 2023     - Creation                                            
//                                                                        
//------------------------------------------------------------------------
//!  Description:    01.02.03                                    
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
    1,
    1,
    &cmd_in.init_time_ms,
    0,
    65535,

    //durata fase misura frequenza,
    2,
    CTRL_INPUT,
    uint,
    &mb.holdingRegisters.dummy2,
    4.371915,
    0.228733,
    &cmd_in.freq_estim_time_ms,
    10,
    15000,

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

    //valore massimo apertura scr,
    5,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy5,
    93621.428571,
    0.000011,
    &scr_sett.scr_cmd_alfa_max,
    0.300000,
    1,

    //valore apertura scr durante il check a 50Hz,
    6,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy6,
    65535,
    0.000015,
    &scr_sett.scr_cmd_alfa_check_50hz,
    0,
    1,

    //valore apertura scr durante il check a 60Hz,
    7,
    SCR_SETTINGS,
    real,
    &mb.holdingRegisters.dummy7,
    65535,
    0.000015,
    &scr_sett.scr_cmd_alfa_check_60hz,
    0,
    1,

    //durata apertura scr ridotta per check,
    8,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy8,
    1,
    1,
    &scr_sett.scr_freeze_ramp_cnt_end,
    0,
    65535,

    //tempo per la rampa scr,
    9,
    SCR_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy9,
    1,
    1,
    &scr_sett.scr_ramp_time_cnt_end,
    0,
    65535,

    //abilita sweep igbt,
    10,
    IGBT_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy10,
    1,
    1,
    &igbt_sett.en_sweep,
    0,
    65535,

    //frequenza principale igbt,
    11,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy11,
    4.369000,
    0.228885,
    &igbt_sett.igbt_main_freq,
    15000,
    30000,

    //range modulante sinusoidale sweep igbt,
    12,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy12,
    3.276750,
    0.305180,
    &igbt_sett.sweep_amplitude,
    0,
    20000,

    //frequenza modulante sinusoidale sweep igbt,
    13,
    IGBT_SETTINGS,
    real,
    &mb.holdingRegisters.dummy13,
    655.350000,
    0.001526,
    &igbt_sett.sweep_freq,
    0,
    100,

    //durata senza sweep igbt per check,
    14,
    IGBT_SETTINGS,
    uint,
    &mb.holdingRegisters.dummy14,
    1,
    1,
    &igbt_sett.freeze_sweep_cnt_end,
    0,
    65535,

    //adattamento adc v_inv_rect_gain,
    15,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy15,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_gain,
    0,
    1000,

    //adattamento adc v_inv_rect_offset,
    16,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy16,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_offset,
    -500,
    500,

    //adattamento adc i_inv_rect_gain,
    17,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy17,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_gain,
    0,
    1000,

    //adattamento adc i_inv_rect_offset,
    18,
    ADC_SETTINGS,
    real,
    &mb.holdingRegisters.dummy18,
    65.535000,
    0.015259,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_offset,
    -500,
    500,

    //valore di scatto sovracorrente AC,
    19,
    PROTECTION,
    real,
    &mb.holdingRegisters.dummy19,
    6553.500000,
    0.000153,
    &protection.i_inv_oc,
    0,
    10
};                                                                        
                                                                          
struct DATA process_data[] =                                              
{                                                                         
    //word stato 1,
    20,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy20,
    1,
    1,
    &sts_out.sts_wd_1,
    0,
    65535,

    //word allarme 1,
    21,
    CTRL_OUTPUT,
    word,
    &mb.holdingRegisters.dummy21,
    1,
    1,
    &sts_out.alm_wd_1,
    0,
    65535,

    //tensione uscita (rms),
    22,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy22,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb.v_inv_f,
    0,
    600,

    //corrente uscita (rms),
    23,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy23,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb.i_inv_f,
    0,
    50,

    //tensione uscita (rettificata),
    24,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy24,
    109.225000,
    0.009155,
    &adc.adc_ctrl_fdb_rect.v_inv_rect_f,
    0,
    600,

    //corrente uscita (rettificata),
    25,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy25,
    1310.700000,
    0.000763,
    &adc.adc_ctrl_fdb_rect.i_inv_rect_f,
    0,
    50,

    //temperatura ntc1,
    26,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy26,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc1_f,
    -20,
    180,

    //temperatura ntc2,
    27,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy27,
    327.675000,
    0.003052,
    &adc.adc_sys.ntc2_f,
    -20,
    180,

    //valore potenziometro,
    28,
    ADC_OUTPUT,
    real,
    &mb.holdingRegisters.dummy28,
    655.350000,
    0.001526,
    &adc.adc_sys.pot_f,
    0,
    100,

    //frequenza attuale igbt,
    29,
    IGBT_OUTPUT,
    real,
    &mb.holdingRegisters.dummy29,
    1.310700,
    0.762951,
    &igbt_out.igbt_actual_freq,
    0,
    50000,

    //tempo freeze sweep igbt,
    30,
    IGBT_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy30,
    1,
    1,
    &igbt_out.freeze_sweep_cnt_ms,
    0,
    65535,

    //contatore isr timer 0,
    31,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy31,
    1,
    1,
    &diagn_out.main_fsm_loop_time_ms,
    0,
    65535,

    //numero conteggi invalidi misura frequenza,
    32,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy32,
    1,
    1,
    &diagn_out.scr_synch_invalid_cnt,
    0,
    65535,

    //inverter datetime - seconds,
    33,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy33,
    1,
    1,
    &diagn_out.datetime.Second,
    0,
    65535,

    //inverter datetime - minutes,
    34,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy34,
    1,
    1,
    &diagn_out.datetime.Minute,
    0,
    65535,

    //inverter datetime - hours,
    35,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy35,
    1,
    1,
    &diagn_out.datetime.Hour,
    0,
    65535,

    //inverter datetime - day,
    36,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy36,
    1,
    1,
    &diagn_out.datetime.Day,
    0,
    65535,

    //inverter datetime - day of week,
    37,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy37,
    1,
    1,
    &diagn_out.datetime.DayOfWeek,
    0,
    65535,

    //inverter datetime - month,
    38,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy38,
    1,
    1,
    &diagn_out.datetime.Month,
    0,
    65535,

    //inverter datetime - year,
    39,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy39,
    1,
    1,
    &diagn_out.datetime.Year,
    0,
    65535,

    //versione firmware - H.L.TYPE,
    40,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy40,
    1,
    1,
    &diagn_out.fmw_version,
    0,
    65535,

    //versione database - DB_IKE_H.L1.L2,
    41,
    DGN_OUTPUT,
    uint,
    &mb.holdingRegisters.dummy41,
    1,
    1,
    &diagn_out.db_version,
    0,
    65535,

    //apertura scr,
    42,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy42,
    65535,
    0.000015,
    &scr_out.scr_cmd_alfa,
    0,
    1,

    //frequenza attuale ingresso,
    43,
    SCR_OUTPUT,
    real,
    &mb.holdingRegisters.dummy43,
    1008.230769,
    0.000992,
    &scr_out.scr_synch_freq,
    0,
    65
};                                                                        
                                                                          
/* #################################################################### */
/* ############################# CODE ################################# */
                                                                          
void updateSingleParamDataIn(unsigned int idx)                            
{                                                                         
    if ((idx >= PARAMS_FIRST_ADDRESS) && (idx <= PARAMS_LAST_ADDRESS))    
    {                                                                     
        switch (params_data[idx].type)                                    
        {                                                                 
        case word:                                                        
        case uint:                                                        
            *(unsigned int*)params_data[idx].val =                        
                ((*params_data[idx].val_modbus *                          
                params_data[idx].k_u16_to_double) +                       
                __f32toui16r(params_data[idx].lim_min));                  
            break;                                                        
        case real:                                                        
            *(float*)params_data[idx].val =                               
                ((*params_data[idx].val_modbus *                          
                params_data[idx].k_u16_to_double) +                       
                params_data[idx].lim_min);                                
            break;                                                        
        }                                                                 
    }                                                                     
}                                                                         
                                                                          
void updateSingleProcessDataOut(unsigned int idx)                         
{                                                                         
    if ((idx >= PROCESS_FIRST_ADDRESS) && (idx <= PROCESS_LAST_ADDRESS))  
    {                                                                     
        switch (process_data[idx].type)                                   
        {                                                                 
        case word:                                                        
        case uint:                                                        
            *process_data[idx].val_modbus =                               
                (*(unsigned int*)process_data[idx].val -                  
                __f32toui16r(process_data[idx].lim_min))*                 
                process_data[idx].k_double_to_u16;                        
            break;                                                        
        case real:                                                        
            *process_data[idx].val_modbus =                               
                (*(float*)process_data[idx].val -                         
                process_data[idx].lim_min)*                               
                process_data[idx].k_double_to_u16;                        
            break;                                                        
        }                                                                 
    }                                                                     
    else if ((idx >= PARAMS_FIRST_ADDRESS) && (idx <= PARAMS_LAST_ADDRESS)) 
    {                                                                     
        switch (params_data[idx].type)                                    
        {                                                                 
        case word:                                                        
        case uint:                                                        
            *params_data[idx].val_modbus =                                
                (*(unsigned int*)params_data[idx].val -                   
                __f32toui16r(params_data[idx].lim_min))*                  
                params_data[idx].k_double_to_u16;                         
            break;                                                        
        case real:                                                        
            *params_data[idx].val_modbus =                                
                (*(float*)params_data[idx].val -                          
                params_data[idx].lim_min)*                                
                params_data[idx].k_double_to_u16;                         
            break;                                                        
        }                                                                 
    }                                                                     
}                                                                         
                                                                          
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
                    __f32toui16r(process_data[i].lim_min)) *              
                process_data[i].k_double_to_u16;                          
            break;                                                        
        case real:                                                        
            *process_data[i].val_modbus =                                 
                (*(float*)process_data[i].val -                           
                    process_data[i].lim_min) *                            
                process_data[i].k_double_to_u16;                          
            break;                                                        
        }                                                                 
    }                                                                     
}                                                                         
                                                                          
/* #################################################################### */
/* #################################################################### */
