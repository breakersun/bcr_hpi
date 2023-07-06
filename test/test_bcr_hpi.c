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

#endif // TEST
