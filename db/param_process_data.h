//########################################################################
//  Project     :   launch_f280039c_template                              
//  Target      :                                                         
//------------------------------------------------------------------------
//  Filename    :   param_process_data.h                                  
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
                                                                          
#ifndef INC_PARAM_PROCESS_DATA_H_                                         
#define INC_PARAM_PROCESS_DATA_H_                                         
                                                                          
                                                                          
/* ## COMMON Section ################################################## */
/* ## These defines are visibles in all files                           */
/* #################################################################### */
                                                                          
/* ## COMMON Includes ################################################# */
                                                                          
/* ## COMMON Defines ################################################## */
                                                                          
#define PARAMS_LENGTH 25
#define PROCESS_LENGTH 24
#define PARAMS_FIRST_ADDRESS 0
#define PARAMS_LAST_ADDRESS PARAMS_FIRST_ADDRESS + PARAMS_LENGTH
#define PROCESS_FIRST_ADDRESS PARAMS_LAST_ADDRESS + 1
#define PROCESS_LAST_ADDRESS PROCESS_FIRST_ADDRESS + PROCESS_LENGTH
#define DB_VERSION_H 02
#define DB_VERSION_L1 03
#define DB_VERSION_L2 01
                                                                          
typedef enum {                                                            
    word = 0,                                                             
    uint = 1,                                                             
    real = 2                                                              
} TYPE;                                                                   
                                                                          
typedef enum {                                                            
    CTRL_INPUT = 0,
    SCR_SETTINGS = 1,
    IGBT_SETTINGS = 2,
    ADC_SETTINGS = 3,
    PROTECTION = 4
} PARAMS_FAMILY;                                                          
                                                                          
typedef enum {                                                            
    CTRL_OUTPUT = 0,
    ADC_OUTPUT = 1,
    IGBT_OUTPUT = 2,
    DGN_OUTPUT = 3,
    SCR_OUTPUT = 4
} PROCESS_FAMILY;                                                         
                                                                          
struct DATA {                                                             
    unsigned int id_address;                                              
    unsigned int group;                                                   
    TYPE type;                                                            
    unsigned int* val_modbus;                                             
    float k_double_to_u16;                                                
    float k_u16_to_double;                                                
    void* val;                                                            
    float lim_min;                                                        
    float lim_max;                                                        
};                                                                        
                                                                          
                                                                          
/* ## EXTERNAL Section ################################################ */
/* ## These Vars/Prototypes are visibles in all files                   */
/* #################################################################### */
                                                                          
/* ## EXTERNAL Prototypes ############################################# */
                                                                          
extern void updateParamsDataIn();                                         
extern void updateProcessDataOut();                                       
                                                                          
/* ## EXTERNAL Vars ################################################### */
                                                                          
extern struct DATA process_data[PROCESS_LENGTH];                          
extern struct DATA param_data[PARAMS_LENGTH];                             
                                                                          
                                                                          
#endif /* INC_PARAM_PROCESS_DATA_H_ */                                    
                                                                          
/* #################################################################### */
/* #################################################################### */
