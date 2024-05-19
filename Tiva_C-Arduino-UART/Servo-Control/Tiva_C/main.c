#include "pins.h"

void configure_pins();
void configure_uart();
void uart_transmit(char);

int main() {
   
  configure_pins();
  configure_uart();
  GPIO_DATA_F = 0;
  int state1, state2;
  while(1) {
     state1 = GPIO_DATA_F & 0x10; // Checking if SW1 button is pressed
     state2 = GPIO_DATA_F & 0x01; // Checking if SW2 button is pressed

     if(state1 == 0) {
       uart_transmit('r');     
     }
     else if(state2 == 0) {
       uart_transmit('l');
     }
     else uart_transmit('m');
  }
  
  return 0; 
}

void configure_pins() {
  /* Enabling Clocks */
  RCGC_UART = 0x4; // Enabling clock to UART 2 (PD6 and PD7)
  RCGC_GPIO = 0x28; // Enabling clock to GPIO F and D
  
  while(RCGC_GPIO & 0x24 == 0);
  
  /* Unlocking GPIO F and D */
  GPIO_LOCK_D = 0x4C4F434B;
  GPIO_LOCK_F = 0x4C4F434B;
  
  GPIO_OCR_D = 0x80; // Enabling writing to PD7 for UART
  GPIO_OCR_F = 0x11; // Enabling writing to PF0 and PF4 for buttons
  
  GPIO_LOCK_D = 0x0;
  GPIO_LOCK_F = 0x0;
  
  /* Setting PD6, PD7, PF0 and PF4 as digital pins */
  GPIO_DEN_D = 0xC0;
  GPIO_DEN_F = 0x11;
  
  /* Configuring PD6 and PD7 as UART */
  GPIO_AFSEL_D = 0xC0; // PD6 and PD7 are controlled by the alternate hardware function
  GPIO_PCTL_D = 0x11000000; // Setting PD6 and PD7's functions as UART pins
  
  /* Configuring PF0 and PF4 for button */
  GPIO_PUR_F = 0x11;
  GPIO_DIR_F = 0xEE; // Setting PF0 and PF4 (buttons) as input
}

void configure_uart() {
  /* Disabling UART for configruatiob */
  UART2_CTL = 0x0;
  
  /* Flushing transmit FIFO bit */
  UART2_LCRH &= 0xEF;
  
  /* Setting baud rate as 9600 */
  UART2_IBRD = 104;
  UART2_FBRD = 11;
  
  /* Configuring serial parameters (8-bit, 1 stop bit, no parity, no FIFO) */
  UART2_LCRH = 0x60;
  
  /* Setting system clock as UART clock source */
  UART2_CC = 0x0;
  
  /* Enabling Rx, Tx pins and UART */
  UART2_CTL = 0x301;
}

void uart_transmit(char data) {
    while(UART2_FR & (1<<5)); // if TX holding register is full, wait until it becomes empty 
    UART2_DATA = data;
}
