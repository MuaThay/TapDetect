/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Tap_Detection.c
 * @brief   Application entry point.
 */
#include <stdint.h>

#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"
#include "board.h"

#include "mma8451.h"
#include "iic.h"


#define DEMO_MODE
#define DEMO_AXIS 0


volatile char acc_data_rdy = 0;

void PORTA_IRQHandler(){
	if(GPIO_GetPinsInterruptFlags(GPIOA) & (1<<15)){
		GPIO_ClearPinsInterruptFlags(GPIOA, (1 << 15));
		acc_data_rdy = 1;
	}
	if(GPIO_GetPinsInterruptFlags(GPIOA) & (1<<14)){
		GPIO_ClearPinsInterruptFlags(GPIOA, (1 << 14));
		LED_RED_TOGGLE();
	}
}

int main(void){
	BOARD_InitPins();
	iic_init();
	mma8451_init();

	EnableIRQ(PORTA_IRQn);


	while(1){


	}
}
