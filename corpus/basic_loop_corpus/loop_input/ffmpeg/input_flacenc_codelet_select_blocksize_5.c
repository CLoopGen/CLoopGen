#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const int32_t ff_flac_blocksize_table[16] = {
    192, 576, 1152, 2304, 4608, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
};

int i;
int target = 4000;
int blocksize = 0;

void init_vars() {
    // No dynamic data to initialize; all variables are either const or scalar
    // Values are already set at file scope
}