/*
 * Copyright (c) 2026 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***************************************************************************//**
 *   @file   main.c
 *   @brief  Hello world for CAPI.
 *
 *   Print a counter on the console UART once a second.
 *   The same source builds for the maxim, alif and stm32 platforms.
*******************************************************************************/
#include "capi_platform.h"
#include "capi_time.h"
#include "capi_uart.h"
#include "parameters.h"
#include <stdio.h>
#include <inttypes.h>

/**
 * @brief Initialize the console UART and print the counter.
 * @return This function does not return.
 */
int main(void)
{
	struct capi_uart_handle *uart = NULL;
	uint32_t count = 0;

	capi_platform_init();

	/* bsp_uart_cfg comes from the board bsp (parameters.h). */
	capi_uart_init(&uart, &bsp_uart_cfg);
	/* printf() reaches the console UART only after capi_stdio_init(). */
	capi_stdio_init(uart);

	printf("\r\n*** capi-hello-world ***\r\n\r\n");

	while (1) {
		count++;
		printf("Hello, World! (#%" PRIu32 ")\r\n", count);
		capi_wait_ms(1000);
	}

	return 0;
}
