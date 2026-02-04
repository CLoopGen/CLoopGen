#include <stdio.h>
#include <inttypes.h>

typedef unsigned char DES_cblock[8];

char *buf;
unsigned int i;
DES_cblock key;
unsigned char c;

char buf_data[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize buffer with non-zero values except for a terminator at the end
    for (int j = 0; j < sizeof(buf_data) - 1; j++) {
        buf_data[j] = (j % 255) + 1; // Avoid zero until the end
    }
    buf_data[sizeof(buf_data) - 1] = 0; // Null terminator to trigger break in loop

    // Initialize pointer to start of buffer
    buf = buf_data;

    // Initialize loop index and other variables
    i = 0;
    c = 0;

    // Clear key array
    for (int j = 0; j < 8; j++) {
        key[j] = 0;
    }
}