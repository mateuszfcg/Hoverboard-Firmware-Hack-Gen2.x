#ifdef MASTER		// layout 2.2 has buzzer on the slave board.
	#define BUZZER
#endif


#define TODO_PORT 	GPIOF		// this should be a pin that does no harm if input or output
#define TODO_PIN	GPIO_PIN_4	// PF4 is only accessible on the largest GD32F130Rx LQFP64 pinouts mcu

// LED defines
#define LED_GREEN TODO_PIN				
#define LED_GREEN_PORT TODO_PORT	
#define LED_ORANGE TODO_PIN				
#define LED_ORANGE_PORT TODO_PORT	
#define LED_RED TODO_PIN					
#define LED_RED_PORT TODO_PORT		

#define UPPER_LED_PIN TODO_PIN		
#define UPPER_LED_PORT TODO_PORT	
#define LOWER_LED_PIN TODO_PIN		
#define LOWER_LED_PORT TODO_PORT	

// Mosfet output
// seems to be an ordinary LED output ?
// led.c:91	gpio_bit_write(MOSFET_OUT_PORT, MOSFET_OUT_PIN, counter_Blue >= setValue_Blue ? RESET : SET); 
#define MOSFET_OUT_PIN TODO_PIN		
#define MOSFET_OUT_PORT TODO_PORT	


// Brushless Control DC (BLDC) defines
#define TIMER_BLDC_PULLUP	GPIO_PUPD_NONE	// robo
// Channel G
#define RCU_TIMER_BLDC RCU_TIMER0
#define TIMER_BLDC TIMER0
#define TIMER_BLDC_CHANNEL_G TIMER_CH_2
#define TIMER_BLDC_GH_PIN GPIO_PIN_10		// TODO
#define TIMER_BLDC_GH_PORT GPIOA				// TODO
#define TIMER_BLDC_GL_PIN GPIO_PIN_15		// TODO
#define TIMER_BLDC_GL_PORT GPIOB				// TODO
// Channel B
#define TIMER_BLDC_CHANNEL_B TIMER_CH_1
#define TIMER_BLDC_BH_PIN GPIO_PIN_9		// TODO
#define TIMER_BLDC_BH_PORT GPIOA				// TODO
#define TIMER_BLDC_BL_PIN GPIO_PIN_14		// TODO
#define TIMER_BLDC_BL_PORT GPIOB				// TODO
// Channel Y
#define TIMER_BLDC_CHANNEL_Y TIMER_CH_0
#define TIMER_BLDC_YH_PIN GPIO_PIN_8		// TODO
#define TIMER_BLDC_YH_PORT GPIOA				// TODO
#define TIMER_BLDC_YL_PIN GPIO_PIN_13		// TODO
#define TIMER_BLDC_YL_PORT GPIOB				// TODO

// Timer BLDC short circuit emergency shutoff define
// Is initialized here but never used somewhere else in code.
// setup.c:176	gpio_mode_set(TIMER_BLDC_EMERGENCY_SHUTDOWN_PORT , GPIO_MODE_AF, GPIO_PUPD_NONE, TIMER_BLDC_EMERGENCY_SHUTDOWN_PIN);  
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PIN GPIO_PIN_12	// TODO
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PORT GPIOB		// TODO

// Hall sensor defines
#define HALL_A_PIN GPIO_PIN_0		// TODO
#define HALL_A_PORT GPIOB				// TODO
#define HALL_B_PIN GPIO_PIN_5		// TODO
#define HALL_B_PORT GPIOB				// TODO
#define HALL_C_PIN GPIO_PIN_4		// TODO
#define HALL_C_PORT GPIOB				// TODO

// Usart master slave defines
#define USART_MASTERSLAVE USART1
#define USART_MASTERSLAVE_TX_PIN GPIO_PIN_2		// TODO
#define USART_MASTERSLAVE_TX_PORT GPIOA				// TODO
#define USART_MASTERSLAVE_RX_PIN GPIO_PIN_3		// TODO
#define USART_MASTERSLAVE_RX_PORT GPIOA				// TODO

// Usart steer defines
#define USART_STEER_COM USART0					// TODO
#define USART_STEER_RCU RCU_USART0
#define USART_STEER_AF	GPIO_AF_0
#define USART_STEER_COM_TX_PIN GPIO_PIN_6		// TODO
#define USART_STEER_COM_TX_PORT GPIOB				// TODO
#define USART_STEER_COM_RX_PIN GPIO_PIN_7		// TODO
#define USART_STEER_COM_RX_PORT GPIOB				// TODO

// ADC defines
#define VBATT_PIN	GPIO_PIN_0				// TODO
#define VBATT_PORT GPIOA						// TODO
#define VBATT_CHANNEL ADC_CHANNEL_4
#define CURRENT_DC_PIN	GPIO_PIN_1	// TODO
#define CURRENT_DC_PORT GPIOA				// TODO
#define CURRENT_DC_CHANNEL ADC_CHANNEL_6

// Self hold defines
// important pin keeps the mosfet open after the on/off button got pushed !
// main.c:306: gpio_bit_write(SELF_HOLD_PORT, SELF_HOLD_PIN, SET); 
// and turns off power on Shutdown:
// main.c:513:	 gpio_bit_write(SELF_HOLD_PORT, SELF_HOLD_PIN, RESET); 
#define SELF_HOLD_PIN GPIO_PIN_2		// TODO
#define SELF_HOLD_PORT GPIOB				// TODO

// Button defines
// on/off (POW) push-button. So also a connection (i guess with some smd resistor in between) to a MCU pin.
// main.c:457: if (gpio_input_bit_get(BUTTON_PORT, BUTTON_PIN)) 
#define BUTTON_PIN GPIO_PIN_15			// TODO
#define BUTTON_PORT GPIOC						// TODO


#ifdef BUZZER
	// Buzzer defines
	#define BUZZER_PIN GPIO_PIN_8		// TODO
	#define BUZZER_PORT GPIOB				// TODO
#endif

#ifdef MASTER
	// Charge state defines
	// This seems to be a digital input that hast to be high in order to enable the motors. 
	// main.c:381: chargeStateLowActive = gpio_input_bit_get(CHARGE_STATE_PORT, CHARGE_STATE_PIN);
	// If not found it should be okay to simply comment this line because chargeStateLowActive in initialised as set = true
	#define CHARGE_STATE_PIN GPIO_PIN_0		
	#define CHARGE_STATE_PORT GPIOF				
#endif

// Debug pin defines - seems to be never used in code.
#define DEBUG_PIN TODO_PIN
#define DEBUG_PORT TODO_PORT

