#ifndef DEFINES_H
#define DEFINES_H

//#include "gd32f1x0.h"
#include "../Inc/config.h"


#ifdef LAYOUT_2_0
	#include "defines_2-0.h"		// https://github.com/flo199213/Hoverboard-Firmware-Hack-Gen2
	// hall input pins A,B,C = B11,F1,C14 , etc.
#endif
#ifdef LAYOUT_2_1
	#include "defines_2-1.h"		// https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1
#endif
#ifdef LAYOUT_2_2
	#include "defines_2-2.h"		// https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1
#endif
#ifdef LAYOUT_2_3
	#include "defines_2-3.h"		// https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/20
#endif
#ifdef LAYOUT_2_4
	#include "defines_2-4.h"		// https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/3
#endif
#ifdef LAYOUT_2_7
	#include "defines_2-7.h"		// https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/16
#endif

#ifdef DEBUG_LED_PIN
  #define DEBUG_LedSet(bSet){gpio_bit_write(DEBUG_LED_PORT, DEBUG_LED_PIN, bSet);}
#else
  #define DEBUG_LedSet(bSet)
#endif

// ADC value conversion defines
#define MOTOR_AMP_CONV_DC_AMP 0.201465201465  // 3,3V * 1/3 - 0,004Ohm * IL(ampere) = (ADC-Data/4095) *3,3V
#define ADC_BATTERY_VOLT      0.024169921875 	// V_Batt to V_BattMeasure = factor 30: ( (ADC-Data/4095) *3,3V *30 )

// Useful math function defines
#define ABS(a) (((a) < 0.0) ? -(a) : (a))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define MAX(x, high) (((x) > (high)) ? (high) : (x))
#define MAP(x, xMin, xMax, yMin, yMax) ((x - xMin) * (yMax - yMin) / (xMax - xMin) + yMin)

// ################################################################################
#ifdef MASTER
	#ifdef USART_CRSF
		#define CRSF_SIGNAL_OK          0x00
		#define CRSF_SIGNAL_LOST        0x01
		//#define CRSF_SIGNAL_FAILSAFE    0x03

		//ELRS
		/*
		 * CRSF protocol
		 *
		 * CRSF protocol uses a single wire half duplex uart connection.
		 * The master sends one frame every 4ms and the slave replies between two frames from the master.
		 *
		 * 420000 baud
		 * not inverted
		 * 8 Bit
		 * 1 Stop bit
		 * Big endian
		 * 420000 bit/s = 46667 byte/s (including stop bit) = 21.43us per byte
		 * Max frame size is 64 bytes
		 * A 64 byte frame plus 1 sync byte can be transmitted in 1393 microseconds.
		 *
		 * CRSF_TIME_NEEDED_PER_FRAME_US is set conservatively at 1500 microseconds
		 *
		 * Every frame has the structure:
		 * <Device address><Frame length><Type><Payload><CRC>
		 *
		 * Device address: (uint8_t)
		 * Frame length:   length in  bytes including Type (uint8_t)
		 * Type:           (uint8_t)
		 * CRC:            (uint8_t)
		 *
		 */

		// Basic setup
		#define CRSF_MAX_CHANNEL 16
		#define CRSF_FRAME_SIZE_MAX 64
		 // Device address & type, The address means the destination of the data packet, so for decoder, the destination is the FC.
		#define ADDR_MODULE                    0xEE  //  Crossfire transmitter
		// Baud ELRS receiver baud 420000 bit/s v2
		#define SERIAL_BAUDRATE 115200 
		#define ADDR_RADIO                     0xEA  //  Radio Transmitter
		#define TYPE_SETTINGS_WRITE            0x2D
		#define CRSF_ADDRESS_FLIGHT_CONTROLLER 0xC8  // Flight Controler

		//Define channel input limite
		#define CRSF_CHANNEL_MIN 172
		#define CRSF_CHANNEL_MID 991
		#define CRSF_CHANNEL_MAX 1811

		// internal crsf variables
		#define CRSF_TIME_NEEDED_PER_FRAME_US   1100 // 700 ms + 400 ms for potential ad-hoc request
		#define CRSF_TIME_BETWEEN_FRAMES_US     6667 // At fastest, frames are sent by the transmitter every 6.667 milliseconds, 150 Hz
		#define CRSF_PACKET_TIMEOUT_US 100000
		#define CRSF_PAYLOAD_OFFSET offsetof(crsfFrameDef_t, type)
		#define CRSF_MAX_CHANNEL 16
		#define CRSF_FRAME_SIZE_MAX 64
		#define CRSF_MSP_RX_BUF_SIZE 128
		#define CRSF_MSP_TX_BUF_SIZE 128
		#define CRSF_PAYLOAD_SIZE_MAX   60
		#define CRSF_PACKET_LENGTH 22
		#define CRSF_PACKET_SIZE  26
		#define CRSF_FRAME_LENGTH 24  // length of type + payload + crc
	#endif
#endif
// ################################################################################

// ADC buffer struct
typedef struct
{
  uint16_t v_batt;
	uint16_t current_dc;
} adc_buf_t;

//#pragma pack(1)
typedef struct
{
  uint8_t wState;
	float currentDC; 									// global variable for current dc
	float realSpeed; 									// global variable for real Speed
	int32_t iOdom;	
} DataSlave;



#endif		// DEFINES_H
