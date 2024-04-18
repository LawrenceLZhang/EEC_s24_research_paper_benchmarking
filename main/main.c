/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "test.h"

#define TEST_ALL

#if !defined(TEST_HW)
    #undef ESP32_CRYPTO_CIPHER_SUPPORT
#endif

#if defined(TEST_AES) || defined(TEST_HW)
    #include "aes_test.h"   
#elif defined(TEST_DES)
    #include "des_test.h"
#elif defined(TEST_DES3)
    #include "des3_test.h"
#elif defined(TEST_BLOWFISH)
    #include "blowfish_test.h"
#elif defined(TEST_TWOFISH)
    #include "twofish_test.h"
#elif defined(TEST_SERPENT)
    #include "serpent_test.h"
#elif defined(TEST_XTEA)
    #include "xtea_test.h"
#elif defined(TEST_ALL)
    #include "aes_test.h"
    #include "des_test.h"
    #include "des3_test.h"
    #include "blowfish_test.h"
    #include "twofish_test.h"
    #include "serpent_test.h"
    #include "xtea_test.h"
#endif

uint8_t buffer[(int) BUFFER_SIZE];

void app_main()
{
    printf("\nPerformance Tests:\n");

    #if defined(TEST_AES)
        testAES();
    #elif defined(TEST_HW)
        testAESHW();
    #elif defined(TEST_DES)
        testDES();
    #elif defined(TEST_DES3)
        testDES3();
    #elif defined(TEST_BLOWFISH)
        testBlowfish();
    #elif defined(TEST_TWOFISH)
        testTwofish();
    #elif defined(TEST_SERPENT)
        testSerpent();
    #elif defined(TEST_XTEA)
        testXTEA();
    #elif defined(TEST_ALL)
        testAES();
        testDES();
        testDES3();
        testBlowfish();
        testTwofish();
        testSerpent();
        testXTEA();
    #endif
}