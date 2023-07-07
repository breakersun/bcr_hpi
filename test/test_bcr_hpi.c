#ifdef TEST

#include "unity.h"
#include "mock_platform_i2c.h"
#include "bcr_hpi.h"

ctx_t platform_ctx;

void setUp(void)
{
    platform_ctx.write_reg = platform_i2c_write;
    platform_ctx.read_reg = platform_i2c_read;
}

void tearDown(void)
{
}

void test_bcr_hpi_ReturnNeg1WhenInvalidCtx(void)
{
    uint16_t uint16_input_holder;
    uint8_t uint8_input_holder;

    // ctx is null
    TEST_ASSERT_EQUAL(-1, cypd3177_get_silicon_id(NULL, &uint16_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_mode(NULL, &uint8_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_interrupt(NULL, &uint8_input_holder));
    // write_reg is null
    platform_ctx.read_reg = platform_i2c_read;
    platform_ctx.write_reg = NULL;
    TEST_ASSERT_EQUAL(-1, cypd3177_get_silicon_id(&platform_ctx, &uint16_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_mode(&platform_ctx, &uint8_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_interrupt(&platform_ctx, &uint8_input_holder));
    // read_reg is null
    platform_ctx.read_reg = NULL;
    platform_ctx.write_reg = platform_i2c_write;
    TEST_ASSERT_EQUAL(-1, cypd3177_get_silicon_id(&platform_ctx, &uint16_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_mode(&platform_ctx, &uint8_input_holder));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_interrupt(&platform_ctx, &uint8_input_holder));
}

void test_bcr_hpi_ReturnNeg1WhenInvalidInputHolder(void)
{
    TEST_ASSERT_EQUAL(-1, cypd3177_get_silicon_id(&platform_ctx, NULL));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_mode(&platform_ctx, NULL));
    TEST_ASSERT_EQUAL(-1, cypd3177_get_device_interrupt(&platform_ctx, NULL));
}

void test_bcr_hpi_DeviceModeGet(void)
{
    uint8_t mode = 0;
    platform_i2c_read_ExpectAndReturn(NULL, DEVICE_MODE_REG, &mode, 1, 0);
    TEST_ASSERT_EQUAL(0, cypd3177_get_device_mode(&platform_ctx, &mode));
}

void test_bcr_hpi_GetDeviceId(void)
{
    uint16_t id = 0;
    platform_i2c_read_ExpectAndReturn(NULL, SILICON_ID_REG, &id, 2, 0);
    TEST_ASSERT_EQUAL(0, cypd3177_get_silicon_id(&platform_ctx, &id));
}

void test_bcr_hpi_ThruPointers(void)
{
    uint16_t id;
    platform_i2c_read_ExpectAnyArgsAndReturn(0);
    uint16_t result2 = 2;
    platform_i2c_read_ReturnThruPtr_outdata(&result2);
    TEST_ASSERT_EQUAL(0, cypd3177_get_silicon_id(&platform_ctx, &id));
}

#endif // TEST
