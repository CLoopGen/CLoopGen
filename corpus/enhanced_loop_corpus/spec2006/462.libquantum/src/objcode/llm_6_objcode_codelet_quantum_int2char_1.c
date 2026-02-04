#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_j = j;
    for (i = 0; i < size; i++) {
        int shift_amount = (size - i - 1) * 8;
        buf[i] = (unsigned char)(temp_j >> shift_amount);
        temp_j &= ((1 << shift_amount) - 1);
    }
}
