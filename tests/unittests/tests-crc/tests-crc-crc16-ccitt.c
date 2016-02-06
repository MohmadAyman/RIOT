/*
 * Copyright 2016 Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdint.h>

#include "embUnit/embUnit.h"

#include "crc/crc16_ccitt.h"

#include "tests-crc.h"

static int calc_and_compare_crc_with_update(const unsigned char *buf,
        size_t len, size_t split, uint16_t expected)
{
    uint16_t result = crc16_ccitt_calc(buf, split);

    result = crc16_ccitt_update(result, buf + split, len - split);

    return result == expected;
}

static int calc_and_compare_crc(const unsigned char *buf, size_t len,
        uint16_t expected)
{
    uint16_t result = crc16_ccitt_calc(buf, len);

    return result == expected;
}

static void test_crc_crc16_ccitt_sequence(void)
{
    /* Reference values according to
     * http://srecord.sourceforge.net/crc16-ccitt.html */
    {
        unsigned char buf[] = "";
        uint16_t expect = 0x1D0F;

        TEST_ASSERT(calc_and_compare_crc(buf, sizeof(buf) - 1, expect));
        TEST_ASSERT(calc_and_compare_crc_with_update(buf, sizeof(buf) - 1,
                    (sizeof(buf) - 1) / 2, expect)); }

    {
        unsigned char buf[] = "A";
        uint16_t expect = 0x9479;

        TEST_ASSERT(calc_and_compare_crc(buf, sizeof(buf) - 1, expect));
        TEST_ASSERT(calc_and_compare_crc_with_update(buf, sizeof(buf) - 1,
                    (sizeof(buf) - 1) / 2, expect)); }

    {
        unsigned char buf[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                              "AAAA";
        uint16_t expect = 0xE938;

        TEST_ASSERT(calc_and_compare_crc(buf, sizeof(buf) - 1, expect));
        TEST_ASSERT(calc_and_compare_crc_with_update(buf, sizeof(buf) - 1,
                    (sizeof(buf) - 1) / 2, expect)); }

    {
        unsigned char buf[] = "123456789";
        uint16_t expect = 0xE5CC;

        TEST_ASSERT(calc_and_compare_crc(buf, sizeof(buf) - 1, expect));
        TEST_ASSERT(calc_and_compare_crc_with_update(buf, sizeof(buf)
                    - 1, (sizeof(buf) - 1) / 2, expect));
    }

    {
        unsigned char buf[] = { 0x12, 0x34, 0x56, 0x78 };
        uint16_t expect = 0xBA3C;

        TEST_ASSERT(calc_and_compare_crc(buf, sizeof(buf), expect));
        TEST_ASSERT(calc_and_compare_crc_with_update(buf, sizeof(buf),
                    sizeof(buf) / 2, expect));
    }
}

Test *tests_crc_crc16_ccitt_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_crc_crc16_ccitt_sequence),
    };

    EMB_UNIT_TESTCALLER(crc_crc16_ccitt_tests, NULL, NULL, fixtures);

    return (Test *)&crc_crc16_ccitt_tests;
}
