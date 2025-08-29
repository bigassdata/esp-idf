/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdint.h>
#include <string.h>

#include "esp_system.h"
#include "esp_cpu.h"

#include "soc/soc_caps.h"

__attribute__((optimize("O0"))) void __attribute__((noreturn)) abort(void)
{
    _Static_assert(UINTPTR_MAX == 0xffffffff, "abort() assumes 32-bit addresses");
    _Static_assert(SOC_CPU_CORES_NUM < 10, "abort() assumes number of cores is 1 to 9");

    esp_system_abort("abort() called");
}
