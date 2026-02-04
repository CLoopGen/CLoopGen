#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t rem[64];
extern int16_t weight[64];
extern int16_t basis[64];
extern int scale;
extern int i;
extern unsigned int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sum = sum;
    for (i = 0; i < 8 * 8; i++) {
        int b = rem[i] + ((basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
        int w = weight[i];
        b >>= 6;
        ((void)0);
        local_sum += (w * b) * (w * b) >> 4;
        weight[i+1] = weight[i]; // Introduce artificial WAR dependency (write-after-read) and potential WAW
    }
    sum = local_sum;
}
