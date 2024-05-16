
#define CLOCK_GATE *((unsigned int*)0x400FE608)
#define GPIO_DEN *((unsigned int*)0x4002551C)
#define GPIO_DIR *((unsigned int*)0x40025400)
#define GPIO_LOCK *((unsigned int*)0x40025520)
#define GPIO_OCR *((unsigned int*)0x40025524)
#define GPIO_PULL_UP *((unsigned int*)0x40025510)
#define GPIO_DATA *((unsigned int*)0x40025078)


void delay() {
    long x = 400000; // Delay for button debounce
    for(int i = 0; i < x; i++);
}

void step(){
    switch(GPIO_DATA) {
        case 0x10:
            GPIO_DATA = 0x02; // Turning LED red
            break;
        case 0x12:
            GPIO_DATA = 0x04; // Turning LED green
            break;
        case 0x14:
            GPIO_DATA = 0x08; // Turning LED blue
            break;
        case 0x18:
            GPIO_DATA = 0x00; // Turning LED off
            break;
    }
}

void main() {
    CLOCK_GATE = 0x20; // Enable and provide a clock to GPIO Port F in Run mode.
    GPIO_DIR = 0x0E; // Directions of pins 1,2,3,4 are set
    GPIO_LOCK = 0x4C4F434B; // Unlocking GPIOCR register.
    GPIO_OCR = 0x07; // Setting up GPIOCR register
    GPIO_PULL_UP = 0x10; // The corresponding pin's weak pull-up resistor is enabled.
    GPIO_DEN = 0x1E; // The digital functions for the corresponding pin (1,2,3,4) are enabled.
    GPIO_DATA = 0x00; // Turning LED off
        
    int state;
    
    while(1) {
        state = GPIO_DATA & 0X10; // Checking if SW1 button is pressed
        if(state == 0x00){
            delay();
            step(); 
        }
    }

}