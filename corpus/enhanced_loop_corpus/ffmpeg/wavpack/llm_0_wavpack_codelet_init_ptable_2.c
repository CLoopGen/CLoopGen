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
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < (1 << 8) / 2; i++) {
            table[i] = value;
            table[(1 << 8) - 1 - i] = 16842751 - value;
            if (value > 65536) {
                rate += (rate * rate_s + 128) >> 8;
                for (int c = (rate + 64) >> 7; c--;)
                    value += (65536 - value) >> 8;
            }
        }
    }
}
