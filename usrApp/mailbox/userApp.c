#include "uart.h"
#include "ucos/includes.h"

extern void PUT32(unsigned int, unsigned int);
extern unsigned int GET32(unsigned int);
#define GPSETO 0x3F20001C
#define GPCLR0 0x3F200028

void userApp2(void *args) {
  while (1) {
    // PUT32(GPSETO, 1 << 16);
    uart_string("in userApp2");
    OSTimeDly(100);
  }
}

void userApp1(void *args) {
  while (1) {
    uart_string("in userApp1");
    OSTimeDly(100);
    // PUT32(GPCLR0, 1 << 16);
  }
}

void uartRS(void *args) {
  while (1) {
    uart_send(uart_recv());
  }
}

void processor_id(void *args) {
  while (1) {
    uart_string("processor id:");
    char *id = get_processor_id();
    hexstrings(id);
  }
}
