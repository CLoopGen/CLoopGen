#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ch;
uint8_t extended_channel_map[16];

void init_vars() {
    // No dynamic allocation needed, all variables are file-scope and statically allocated
    // Array size is fixed at 16, so no additional initialization required for bounds safety
    // Loop in 'loop()' function runs from ch=0 to ch<16, which is within bounds
}