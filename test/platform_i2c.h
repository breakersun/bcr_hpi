#include <stdint.h>
int32_t platform_i2c_write(void *handle, uint16_t reg, const uint8_t *data, uint16_t len);
int32_t platform_i2c_read(void *handle, uint16_t reg, uint8_t *outdata, uint16_t len);
