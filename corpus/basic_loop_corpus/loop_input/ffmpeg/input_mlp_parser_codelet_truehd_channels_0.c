#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t thd_chancount[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int chanmap = 0x1FFF; // All 13 bits set
int channels = 0;
int i = 0;

void init_vars() {
    // No dynamic allocation needed; all variables are statically defined
    // Ensure chanmap uses only lower 13 bits to match loop logic
    chanmap &= 0x1FFF;
}