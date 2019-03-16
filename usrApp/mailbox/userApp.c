#include "uart.h"
#include "ucos/includes.h"

extern void PUT32(unsigned int, unsigned int);
extern unsigned int GET32(unsigned int);
#define GPSETO 0x3F20001C
#define GPCLR0 0x3F200028
OS_EVENT *Mbox1;

void userApp2(void *args) {
  char *Msg;
  INT8U err;

  while (1) {
    // PUT32(GPSETO, 1 << 16);
    uart_string("in userApp2");
    // Msg = (char *)OSMboxPend(Mbox1, 0, &err);
    Msg = (char *)OSMboxAccept(Mbox1);
    uart_string(Msg);
    OSTimeDly(100);
  }
}

void userApp1(void *args) {
  char txmsg = 'A';
  while (1) {
    uart_string("in userApp1");
    OSMboxPost(Mbox1, (void *)&txmsg);
    txmsg++;
    if (txmsg == 'Z') {
      txmsg = 'A'; /* Start new series of messages                       */
    }
    OSTimeDly(100);
    // PUT32(GPCLR0, 1 << 16);
  }
}

void uartRS(void *args) {
  while (1) {
    uart_send(uart_recv());
  }
}

void createMbox(void *args) {
  uart_string("enter createMbox");
  Mbox1 = OSMboxCreate((void *)0);
  uart_string("Create first mailbox name Mbox1");
  while (1) {
    OSTimeDly(100);
  }
}

void processor_id(void *args) {
  while (1) {
    uart_string("processor id:");
    char *id = get_processor_id();
    hexstrings(id);
  }
}
