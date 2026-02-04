#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define DATA_SIZE (1 << 20) // 1MB of data

unsigned short *x;
unsigned short *y;
unsigned int a;
int i;
unsigned int carry;

static unsigned short x_storage[DATA_SIZE / sizeof(unsigned short)];
static unsigned short y_storage[DATA_SIZE / sizeof(unsigned short)];

void init_vars() {
    carry = 0;
    a = 0;
    i = 0;

    // Set pointers to point at the middle of the storage arrays to allow decrementing
    // The loop runs from i=2 to i<9 (7 iterations), so we need at least 7 elements before the start
    const int offset = 8;
    x = &x_storage[offset];
    y = &y_storage[offset];

    // Initialize x and y storage with non-zero values for meaningful computation
    for (int j = 0; j < DATA_SIZE / sizeof(unsigned short); j++) {
        x_storage[j] = (unsigned short)(j & 0xFFFF);
        y_storage[j] = (unsigned short)((j ^ 0x5555) & 0xFFFF);
    }
}