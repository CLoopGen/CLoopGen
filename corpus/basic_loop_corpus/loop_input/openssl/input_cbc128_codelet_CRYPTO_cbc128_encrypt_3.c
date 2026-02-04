#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

unsigned char *out;
size_t n;
unsigned char *iv;

void init_vars() {
    size_t data_size = 1024 * 128; // 128 KB of data
    out = (unsigned char *)malloc(data_size);
    iv = (unsigned char *)malloc(data_size);
    if (!out || !iv) {
        exit(1);
    }
    memset(iv, 0xAA, data_size); // Initialize iv with sample data
    memset(out, 0x00, data_size); // Initialize out to zero
    n = 0; // Ensure loop starts at 0 and runs while n < 16
}