/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Ortmann <ludwig.ortmann@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <periph/gpio.h>
#include <periph_conf.h>
short i=0;

int main(void)
{
    puts("Hello World!");
    gpio_init(1,GPIO_DIR_OUT, 0);
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);
    gpio_init_af(3, GPIO_AF0);
    gpio_irq_enable(10);
    gpio_set(2);
    gpio_clear(2);
    gpio_toggle(4);
    gpio_write(5,1);
    gpio_read(5);
    gpio_irq_enable(10);
    gpio_init_int(1,0, 0, 0,0);
    while(1){
        i++;
        printf("%d\n", i);
        if(i==100)
            i = 0;
    }
    return 0;
}
