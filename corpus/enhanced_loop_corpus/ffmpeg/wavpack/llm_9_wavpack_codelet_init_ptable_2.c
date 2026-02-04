#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int rate_s;
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 9) / 4; i += 2) {
    int idx1 = i;
    int idx2 = (1 << 8) - 1 - i;
    table[idx1] = value + ((value & 0xFF) * 2);
    table[idx2] = 16842751 - value;
    if (value > 131072) {
        rate += (rate * (rate_s >> 1) + 64) >> 9;
        for (int c = (rate + 32) >> 8; c > 0; c--) {
            value += (65536 - value) >> 9;
        }
    }
    if (i + 1 < (1 << 8) / 4) {
        table[idx1 + 1] = value ^ 0xFFFF;
        table[(1 << 8) - 2 - i] = 16842751 - (value ^ 0xFFFF);
    }
}
}
