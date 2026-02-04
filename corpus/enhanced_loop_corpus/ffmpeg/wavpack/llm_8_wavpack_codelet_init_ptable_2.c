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
for (int i = 0; i < (1 << 7); i++) {
    table[i] = value ^ (value << 1);
    table[(1 << 8) - 1 - i] = 16842751 - (value + (value >> 2));
    if (value > 32768) {
        rate += (rate * rate_s + 256) >> 7;
        for (int c = (rate + 128) >> 6; c--;) {
            value += (32768 - value) >> 7;
            value -= (value >> 4) & 0xFF;
        }
    }
}
}
