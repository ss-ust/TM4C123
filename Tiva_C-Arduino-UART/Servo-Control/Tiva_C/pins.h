#define RCGC_GPIO *((unsigned int*)0x400FE608)
#define RCGC_UART *((unsigned int*)0x400FE618)

#define GPIO_LOCK_D *((unsigned int*)0x40007520)
#define GPIO_LOCK_F *((unsigned int*)0x40025520)

#define GPIO_OCR_D *((unsigned int*)0x40007524)
#define GPIO_OCR_F *((unsigned int*)0x40025524)

#define GPIO_AFSEL_D *((unsigned int*)0x40007420)
#define GPIO_PCTL_D *((unsigned int*)0x4000752C)

#define GPIO_DATA_F *((unsigned int*)0x40025044)
#define GPIO_DIR_F *((unsigned int*)0x40025400)

#define GPIO_DEN_D *((unsigned int*)0x4000751C)
#define GPIO_DEN_F *((unsigned int*)0x4002551C)

#define GPIO_PUR_F *((unsigned int*)0x40025510)

#define UART2_CTL *((unsigned int*)0x4000E030)
#define UART2_LCRH *((unsigned int*)0x4000E02C)

#define UART2_IBRD *((unsigned int*)0x4000E024)
#define UART2_FBRD *((unsigned int*)0x4000E028)
#define UART2_CC *((unsigned int*)0x4000EFC8)
#define UART2_FR *((unsigned int*)0x4000E018)
#define UART2_DATA *((unsigned int*)0x4000E000)