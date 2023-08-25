#pragma once

#ifdef __MAIN__
#define EXTERN
#define DSPINIT(a) = a;
#else
#define EXTERN extern
#define DSPINIT(a) ;
#endif

#include <stdint.h>

//#define uint16_t unsigned int
//#define uint32_t unsigned long

#define SERIAL_CRLF    "\r\n"
#define USART_MSG_LENGTH 10

struct CMDSTS_BIT {
    uint8_t read_cmd : 1;			// bit0
    uint8_t chksm_rx_err_sts : 7;	// bit1..bit7
};

typedef union CMDSTS {
    uint8_t all;
    struct CMDSTS_BIT bit;
} CMDSTS;

typedef struct {
    uint8_t data_id[2];
    uint8_t data_val[4];
    CMDSTS cmd_sts;
    uint8_t artifact;
    uint8_t checksum;
    uint8_t lf;
} USART_TX_MSG;

typedef union USART_RX_MSG {
    uint8_t all[USART_MSG_LENGTH];
    USART_TX_MSG byte;
} USART_RX_MSG;

/* Command Word 1 */
struct CMD_BIT {
    uint16_t SWITCH_ON : 1;         // bit0
    uint16_t b1 : 1;                // bit1
    uint16_t b2 : 1;                // bit2
    uint16_t b3 : 1;                // bit3
    uint16_t b4 : 1;                // bit4
    uint16_t b5 : 1;                // bit5
    uint16_t b6 : 1;                // bit6
    uint16_t FAULT_ACK : 1;         // bit7
    uint16_t RESERVED1 : 1;         // bit8
    uint16_t b9 : 1;                // bit9
    uint16_t REMOTE_CONTROL : 1;    // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t RESERVED2 : 1;         // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t RESERVED3 : 1;         // bit15
};
typedef union CMD_WD1 {
    uint16_t all;
    struct CMD_BIT bit;
} CMD_WD1;

/* Status Word 1 */
struct STS_BIT {
    uint16_t INITIALIZED : 1;       // bit0
    uint16_t FREQ_ESTIMATED : 1;    // bit1
    uint16_t READY_TO_OPERATE : 1;  // bit2
    uint16_t OP_ENABLED : 1;        // bit3
    uint16_t FAULT : 1;             // bit4
    uint16_t PULSE_ENABLED : 1;     // bit5
    uint16_t WARNING : 1;           // bit6
    uint16_t SDCARD_ENABLED : 1;    // bit7
    uint16_t RTC_ENABLED : 1;       // bit8
    uint16_t b9 : 1;                // bit9
    uint16_t b10 : 1;               // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t b13 : 1;               // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t b15 : 1;               // bit15
};
typedef union STS_WD1 {
    uint16_t all;
    struct STS_BIT bit;
} STS_WD1;

/* Alarm Word 1 */
struct ALM_BIT {
    uint16_t SYNCH_SCR_LOST : 1;    // bit0
    uint16_t FREQ_SCR_UNDEF : 1;    // bit1
    uint16_t DESAT : 1;             // bit2
    uint16_t OVER_CURRENT : 1;      // bit3
    uint16_t UNDER_CURRENT : 1;     // bit4
    uint16_t OVER_VOLTAGE : 1;      // bit5
    uint16_t UNDER_VOLTAGE : 1;     // bit6
    uint16_t PSUPLLY : 1;           // bit7
    uint16_t EXTERNAL_FLT : 1;      // bit8
    uint16_t OH1 : 1;               // bit9
    uint16_t OH2 : 1;               // bit10
    uint16_t b11 : 1;               // bit11
    uint16_t b12 : 1;               // bit12
    uint16_t b13 : 1;               // bit13
    uint16_t b14 : 1;               // bit14
    uint16_t b15 : 1;               // bit15
};
typedef union ALM_WD1 {
    uint16_t all;
    struct ALM_BIT bit;
} ALM_WD1;

/* Adc Signals */
typedef struct {
    uint16_t v_inv;
    uint16_t i_inv;
    float v_inv_f;
    float i_inv_f;
} ADC_CTRL_FDB;
typedef struct {
    uint16_t v_inv_rect;
    uint16_t i_inv_rect;
    float v_inv_rect_gain;
    int16_t v_inv_rect_offset;
    float i_inv_rect_gain;
    int16_t i_inv_rect_offset;
    float v_inv_rect_f;
    float i_inv_rect_f;
} ADC_CTRL_FDB_RECT;
typedef struct {
    uint16_t ntc1;
    uint16_t ntc2;
    uint16_t pot;
    float ntc1_gain;
    int16_t ntc1_offset;
    float ntc2_gain;
    int16_t ntc2_offset;
    float pot_gain;
    int16_t pot_offset;
    float ntc1_f;
    float ntc2_f;
    float pot_f;
} ADC_SYS;
typedef struct {
    ADC_CTRL_FDB adc_ctrl_fdb;
    ADC_CTRL_FDB_RECT adc_ctrl_fdb_rect;
    ADC_SYS adc_sys;
} ADC;
#define ADC_DEFAULT { \
    0U, 0U, 0.0f, 0.0f, \
    0U, 0U, 1.0f, 0, 1.0f, 0, 0.0f, 0.0f, \
    0U, 0U, 0U, 1.0f, 0, 1.0f, 0, 1.0f, 0, 0.0f, 0.0f, 0.0f \
}

/* Drive State */
typedef enum {
    INIT = 0,              // iniz. periferiche e com. con system
    FREQ_ESTIMATION = 1,   // ecap sta camp. la freq. dell'uscita cmpss
    READY_TO_OPERATE = 2,  // pronto, in attesa di START da system
    OP_ENABLED = 3,        // impulsi attivi scr e igbt
    FAULT = 4              // fault presente
} FSM_MAIN;




typedef enum {
    CTRL_INPUT = 0,
    SCR_SETTINGS = 1,
    IGBT_SETTINGS = 2,
    ADC_SETTINGS = 3,
    PROTECTION = 4,
    CTRL_OUTPUT = 50,
    ADC_OUTPUT = 51,
    SCR_OUTPUT = 52,
    IGBT_OUTPUT = 53,
    DGN_OUTPUT = 54
} FAM_GROUP;

/* Data */
struct DATA {
    uint32_t id;
    FAM_GROUP group;
    uint16_t num_byte;
    void* val;
};

/**
 * USART Msg Structure:
 *
 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]   [7]        [8]	 [9]
 *  	---------------------------------------------------------------------------
 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | CMD | ARTIFACT | CHKSM | LF |
 *  	---------------------------------------------------------------------------
 */
#define CAN_ADDRESS_LENGTH             	2
#define CAN_DATA_LENGTH               	4
#define USART_ARTIFACT					1
#define USART_STS						1
#define USART_CHECKSUM					1
#define USART_LF		              	1
#define USART_MSG_LENGTH              	10/*CAN_ADDRESS_LENGTH + \
									  	CAN_DATA_LENGTH + \
										USART_ARTIFACT + \
										USART_STS + \
										USART_CHECKSUM + \
										USART_LF*/
#define CMD_WRITE                       0x00
#define CMD_READ                        0x01

/* ========================================================= *
 * SERVICE DEVICE OBJECT (SDO)
 * ========================================================= */

#define SDO_LENGTH 26

#define ID_SDO_00 0x0200
#define ID_SDO_01 0x0201
#define ID_SDO_02 0x0202
#define ID_SDO_03 0x0203
#define ID_SDO_04 0x0204
#define ID_SDO_05 0x0205
#define ID_SDO_06 0x0206
#define ID_SDO_07 0x0207
#define ID_SDO_08 0x0208
#define ID_SDO_09 0x0209
#define ID_SDO_10 0x020A
#define ID_SDO_11 0x020B
#define ID_SDO_12 0x020C
#define ID_SDO_13 0x020D
#define ID_SDO_14 0x020E
#define ID_SDO_15 0x020F
#define ID_SDO_16 0x0210
#define ID_SDO_17 0x0211
#define ID_SDO_18 0x0212
#define ID_SDO_19 0x0213
#define ID_SDO_20 0x0214
#define ID_SDO_21 0x0215
#define ID_SDO_22 0x0216
#define ID_SDO_23 0x0217
#define ID_SDO_24 0x0218
#define ID_SDO_25 0x0219

#define ID_SDO_00_BYTE 2
#define ID_SDO_01_BYTE 2
#define ID_SDO_02_BYTE 2
#define ID_SDO_03_BYTE 2
#define ID_SDO_04_BYTE 4
#define ID_SDO_05_BYTE 4
#define ID_SDO_06_BYTE 4
#define ID_SDO_07_BYTE 2
#define ID_SDO_08_BYTE 4
#define ID_SDO_09_BYTE 4
#define ID_SDO_10_BYTE 4
#define ID_SDO_11_BYTE 4
#define ID_SDO_12_BYTE 4
#define ID_SDO_13_BYTE 2
#define ID_SDO_14_BYTE 4
#define ID_SDO_15_BYTE 2
#define ID_SDO_16_BYTE 4
#define ID_SDO_17_BYTE 2
#define ID_SDO_18_BYTE 4
#define ID_SDO_19_BYTE 2
#define ID_SDO_20_BYTE 4
#define ID_SDO_21_BYTE 2
#define ID_SDO_22_BYTE 4
#define ID_SDO_23_BYTE 2
#define ID_SDO_24_BYTE 4
#define ID_SDO_25_BYTE 2

 /* ========================================================= *
  * PROCESS DATA OBJECT (PDO)
  * ========================================================= */

#define PDO_LENGTH 14

#define ID_PDO_00 0x0100
#define ID_PDO_01 0x0101
#define ID_PDO_02 0x0102
#define ID_PDO_03 0x0103
#define ID_PDO_04 0x0104
#define ID_PDO_05 0x0105
#define ID_PDO_06 0x0106
#define ID_PDO_07 0x0107
#define ID_PDO_08 0x0108
#define ID_PDO_09 0x0109
#define ID_PDO_10 0x010A
#define ID_PDO_11 0x010B
#define ID_PDO_12 0x010C
#define ID_PDO_13 0x010D

#define ID_PDO_00_BYTE 2
#define ID_PDO_01_BYTE 2
#define ID_PDO_02_BYTE 4
#define ID_PDO_03_BYTE 4
#define ID_PDO_04_BYTE 4
#define ID_PDO_05_BYTE 4
#define ID_PDO_06_BYTE 4
#define ID_PDO_07_BYTE 4
#define ID_PDO_08_BYTE 4
#define ID_PDO_09_BYTE 4
#define ID_PDO_10_BYTE 4
#define ID_PDO_11_BYTE 4
#define ID_PDO_12_BYTE 2
#define ID_PDO_13_BYTE 4

  /* ## EXTERNAL Vars ################################################### */

  /* PDO and SDO */
extern struct DATA process_data[PDO_LENGTH];
extern struct DATA param_data[SDO_LENGTH];
extern uint16_t en_pdo_send;
/* general */
EXTERN uint16_t dummy_location          DSPINIT(0U)
EXTERN uint32_t main_fsm_loop_cnt       DSPINIT(0U)
/* variables for analog in */
EXTERN ADC adc                          DSPINIT(ADC_DEFAULT)
/* variables for digital in start_cmd */
EXTERN uint16_t start_cmd_counter       DSPINIT(0U)     // [ms]
EXTERN uint16_t start_cmd_filter        DSPINIT(20U)    // [ms]
EXTERN uint16_t start_cmd_qualified     DSPINIT(0U)
EXTERN uint16_t start_cmd_qualified_d   DSPINIT(0U)
/* variables for digital in oh1 */
EXTERN uint16_t oh1_counter             DSPINIT(0U)     // [ms]
EXTERN uint16_t oh1_filter              DSPINIT(20U)    // [ms]
EXTERN uint16_t oh1_qualified           DSPINIT(0U)
EXTERN uint16_t fault_ack               DSPINIT(0U)
EXTERN uint16_t fault_ack_d             DSPINIT(0U)
EXTERN uint16_t resetting_faults        DSPINIT(0U)
/* variables for digital in oh2 */
EXTERN uint16_t oh2_counter             DSPINIT(0U)     // [ms]
EXTERN uint16_t oh2_filter              DSPINIT(20U)    // [ms]
EXTERN uint16_t oh2_qualified           DSPINIT(0U)
/* variables for digital in flt_sup */
EXTERN uint16_t flt_sup_counter         DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_sup_filter          DSPINIT(10U)    // [ms]
EXTERN uint16_t flt_sup_qualified       DSPINIT(0U)
/* variables for digital in flt_gd */
EXTERN uint16_t flt_gd_counter          DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_gd_filter           DSPINIT(0U)     // [ms]
EXTERN uint16_t flt_gd_qualified        DSPINIT(0U)
/* fsm, sts_wd, alm_wd */
EXTERN FSM_MAIN main_state              DSPINIT(INIT)
EXTERN STS_WD1 sts_wd_1                 DSPINIT({ 0U })
EXTERN ALM_WD1 alm_wd_1                 DSPINIT({ 0U })
EXTERN CMD_WD1 cmd_wd_1                 DSPINIT({ 0U })
EXTERN uint16_t init_cnt_ms             DSPINIT(0U)     // [ms]
EXTERN uint16_t init_cnt_end            DSPINIT(1000U)  // [ms]
/* variables for ecap input frequency measure */
EXTERN uint32_t ecap_scr_synch_freq_int_cnt     DSPINIT(0UL)
EXTERN float scr_synch_freq             DSPINIT(0.0f)   // [Hz]
EXTERN float scr_synch_freq_bound       DSPINIT(2.0f)   // [Hz]
EXTERN uint16_t scr_synch_estim_cnt_ms  DSPINIT(0U)     // [ms]
EXTERN uint16_t scr_synch_estim_cnt_end DSPINIT(1000U)  // [ms]
EXTERN uint16_t scr_synch_invalid_cnt   DSPINIT(0U)     // [#]
/* variables for scr drivers */
EXTERN uint16_t en_manual_alfa          DSPINIT(0U)     // [#]
EXTERN uint16_t scr_cmd_prd             DSPINIT(15000U) // [epwmclk]
EXTERN uint16_t scr_cmd_cmpa            DSPINIT(20000U) // [epwmclk]
EXTERN uint16_t scr_cmd_cmpb            DSPINIT(13000U) // [epwmclk]
EXTERN float scr_cmd_alfa_set           DSPINIT(0.0f)   // [pu]
EXTERN float scr_cmd_alfa               DSPINIT(0.0f)   // [pu]
EXTERN float scr_cmd_alfa_max           DSPINIT(1.0f)   // [pu]
EXTERN float scr_cmd_alfa_check_50hz    DSPINIT(0.1f)   // [pu]
EXTERN float scr_cmd_alfa_check_60hz    DSPINIT(0.1f)   // [pu]
EXTERN float scr_cmd_alfa_increment     DSPINIT(0.001f) // [pu/ms]
EXTERN uint16_t freeze_scr_ramp_cnt_ms  DSPINIT(0U)     // [ms]
EXTERN uint16_t freeze_scr_ramp_cnt_end DSPINIT(1000U)  // [ms]
/* variables for igbt drivers */
EXTERN uint16_t igbt_cmd_prd            DSPINIT(3000U)  // [epwmclk]
EXTERN uint16_t igbt_cmd_sweep          DSPINIT(0U)     // [epwmclk]
EXTERN uint16_t freeze_sweep_cnt_ms     DSPINIT(0U)     // [ms]
EXTERN uint16_t freeze_sweep_cnt_end    DSPINIT(0U)     // [ms]
EXTERN float igbt_main_freq             DSPINIT(0.5f)   // [Hz]
EXTERN float igbt_actual_freq           DSPINIT(22.0f)  // [Hz]
EXTERN float sweep_amplitude            DSPINIT(0.3f)   // [Hz]
EXTERN float sweep_freq                 DSPINIT(0.1f)   // [Hz]
EXTERN uint16_t en_sweep                DSPINIT(0U)     // [#]
/* variables for cmpss overcurrent */
EXTERN uint16_t overcurr_ac_detect      DSPINIT(0U)
EXTERN float i_inv_oc                   DSPINIT(2.0f)   // [A]
EXTERN uint16_t en_prot_overcurr        DSPINIT(0U)     // [#]