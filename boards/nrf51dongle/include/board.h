/*
 * Copyright (C) 2015 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    boards_nrf51dongle nRF51 Dongle
 * @ingroup     boards
 * @brief       Board specific files for the Nordic nRF51 Dongle
 * @{
 *
 * @file
 * @brief       Board specific configuration for the nRF51 Dongle
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"
#include "periph_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Xtimer configuration
 * @{
 */
#define XTIMER                      (0)
#define XTIMER_CHAN                 (0)
#define XTIMER_MASK                 (0xff000000)
#define XTIMER_SHIFT_ON_COMPARE     (2)
#define XTIMER_BACKOFF              (40)
/** @} */

/**
 * @brief   LED pin definitions and handlers
 * @{
 */
#define LED0_PIN            GPIO_PIN(0, 21)
#define LED1_PIN            GPIO_PIN(0, 22)
#define LED2_PIN            GPIO_PIN(0, 23)

#define LED0_MASK           (1 << 21)
#define LED1_MASK           (1 << 22)
#define LED2_MASK           (1 << 23)

#define LED0_ON             (NRF_GPIO->OUTCLR = LED0_MASK)
#define LED0_OFF            (NRF_GPIO->OUTSET = LED0_MASK)
#define LED0_TOGGLE         (NRF_GPIO->OUT   ^= LED0_MASK)

#define LED1_ON             (NRF_GPIO->OUTCLR = LED1_MASK)
#define LED1_OFF            (NRF_GPIO->OUTSET = LED1_MASK)
#define LED1_TOGGLE         (NRF_GPIO->OUT   ^= LED1_MASK)

#define LED2_ON             (NRF_GPIO->OUTCLR = LED2_MASK)
#define LED2_OFF            (NRF_GPIO->OUTSET = LED2_MASK)
#define LED2_TOGGLE         (NRF_GPIO->OUT   ^= LED2_MASK)
/** @} */

/**
 * @brief   Initialize the board, also triggers the CPU initialization
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /** BOARD_H */
/** @} */
