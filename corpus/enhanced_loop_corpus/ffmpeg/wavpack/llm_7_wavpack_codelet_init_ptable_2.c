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
int local_rate = rate;
int local_value = value;
for (int i = 0; i < (1 << 8) / 2; i++) {
    table[i] = local_value;
    table[(1 << 8) - 1 - i] = 16842751 - local_value;
    if (local_value > 65536) {
        local_rate += (local_rate * rate_s + 128) >> 8;
        for (int c = (local_rate + 64) >> 7; c--;)
            local_value += (65536 - local_value) >> 8;
    }
}
rate = local_rate;
value = local_value;
}
