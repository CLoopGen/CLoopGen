#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

short *hex_digits_ptr = NULL;
ssize_t i;

#define HEX_DIGITS_SIZE (1 << 20) // ~2MB of data: 1M elements * 2 bytes

short hex_digits[HEX_DIGITS_SIZE];

void init_vars() {
    hex_digits_ptr = hex_digits;
    i = 0;
}