/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * Copyright (C) 2023 Ewan Parker.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include "hardware/pio.h"
#include <stdint.h>

void ws2812_init();

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return
            ((uint32_t) (r) << 8) |
            ((uint32_t) (g) << 16) |
            (uint32_t) (b);
}
