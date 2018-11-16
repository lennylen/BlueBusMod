/*
 * File:   uart.h
 * Author: Ted Salmon <tass2001@gmail.com>
 * Summary:
 *      Provides an API for UART module interactions
 */
#ifndef UART_H
#define UART_H
#include <stdint.h>
#include <xc.h>
#include "../mappings.h"
#include "timer.h"
#define UART_BAUD_115200 8
#define UART_BAUD_9600 103
#define UART_U1_TX_MODE 3
#define UART_RX_QUEUE_SIZE 128
#define UART_RX_QUEUE_TIMEOUT 1000

/* Check if a bit is set in a byte */
#define CHECK_BIT(var, pos) ((var) & (1 <<(pos)))

/**
 * UART_t
 *     Description:
 *         This object defines helper functionality to allow us to read and
 *         write data from the UART module
 */
typedef struct UART_t {
    char rxQueue[UART_RX_QUEUE_SIZE];
    uint8_t rxQueueReadCursor;
    uint8_t rxQueueSize;
    uint8_t rxQueueWriteCursor;
    uint32_t rxLastTimestamp;
    volatile UART *registers;
} UART_t;

UART_t UARTInit(uint8_t);
unsigned char UARTGetNextByte(UART_t *);
unsigned char UARTGetOffsetByte(UART_t *, uint8_t);
void UARTReadData(UART_t *);
void UARTResetRxQueue(UART_t *);
void UARTSendData(UART_t *, unsigned char *, uint8_t);
#endif /* UART_H */