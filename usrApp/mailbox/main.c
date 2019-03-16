#include "regs.h"
#include "timer.h"
#include "uart.h"
#include "ucos/includes.h"

OS_STK userAppTaskStk1[1000];
OS_STK userAppTaskStk2[1000];
OS_STK userAppTaskStk3[1000];
OS_STK userAppTaskStk[1000];

extern void userApp1(void *);
extern void userApp2(void *);
extern void uartRS(void *);
extern void createMbox(void *);

void main() {
  uart_init();
  uart_string("uart_init() success!");

  InitInterruptController();
  uart_string("InitInterruptController success!");

  DisableInterrupts();
  uart_string("DisableInterrupts() success!");

  timer_init();
  uart_string("timer_init() success!");

  OSInit();
  uart_string("OSInit() success!");

  OSTaskCreate(createMbox, (void *)0, &userAppTaskStk3[1000 - 1], 5);
  uart_string("Task createMbox creat success!");

  OSTaskCreate(userApp1, (void *)0, &userAppTaskStk1[1000 - 1], 6);
  uart_string("Task userApp1 creat success!");

  OSTaskCreate(userApp2, (void *)0, &userAppTaskStk2[1000 - 1], 7);
  uart_string("Task userApp2 creat success!");

  OSTaskCreate(uartRS, (void *)0, &userAppTaskStk[1000 - 1], 8);
  uart_string("Task uartRS creat success!");

  OSStart();
  uart_string("OSStart() success!");

  while (1)
    ;
}
