#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int16_t * bak;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in two passes to alter spatial locality
    sum = 0;
    for (i = 0; i < 64; i += 2) {
        sum += (temp[i] - bak[i]) * (temp[i] - bak[i]);
    }
    for (i = 1; i < 64; i += 2) {
        sum += (temp[i] - bak[i]) * (temp[i] - bak[i]);
    }
}
