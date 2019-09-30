#ifndef _UART_H
#define _UART_H

void uart_init(void);
void uart_char(char ch);
void uart_print(char *msg);
void uart_printf(char *szFormat, ...);

#endif
