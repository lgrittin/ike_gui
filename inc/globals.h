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
    uint16_t INITIALIZED : 1;           // bit0
    uint16_t FREQ_ESTIMATED : 1;        // bit1
    uint16_t READY_TO_OPERATE : 1;      // bit2
    uint16_t OP_ENABLED : 1;            // bit3
    uint16_t FAULT : 1;                 // bit4
    uint16_t PULSE_ENABLED : 1;         // bit5
    uint16_t WARNING : 1;               // bit6
    uint16_t SDCARD_ENABLED : 1;        // bit7
    uint16_t RTC_ENABLED : 1;           // bit8
    uint16_t IGBT_SWEEP_ENABLED : 1;    // bit9
    uint16_t SCR_MANUAL_ALFA_SET : 1;   // bit10
    uint16_t MUX_STATE : 1;             // bit11
    uint16_t b12 : 1;                   // bit12
    uint16_t b13 : 1;                   // bit13
    uint16_t b14 : 1;                   // bit14
    uint16_t b15 : 1;                   // bit15
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

/* Fmw Version */
struct FMW_VERSION_BIT {
    uint16_t FMW_VER_H : 6;
    uint16_t FMW_VER_L : 6;
    uint16_t FMW_VER_TYPE : 4;
};

typedef union FMW_VERSION {
    uint16_t all;
    struct FMW_VERSION_BIT bit;
} FMW_VERSION;

/* DB Version */
struct DB_VERSION_BIT {
    uint16_t DB_VER_H : 4;
    uint16_t DB_VER_L1 : 6;
    uint16_t DB_VER_L2 : 6;
};

typedef union DB_VERSION {
    uint16_t all;
    struct DB_VERSION_BIT bit;
} DB_VERSION;

/* Drive State */
typedef enum {
    INIT = 0,              // iniz. periferiche e com. con system
    FREQ_ESTIMATION = 1,   // ecap sta camp. la freq. dell'uscita cmpss
    READY_TO_OPERATE = 2,  // pronto, in attesa di START da system
    OP_ENABLED = 3,        // impulsi attivi scr e igbt
    FAULT = 4              // fault presente
} FSM_MAIN;

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