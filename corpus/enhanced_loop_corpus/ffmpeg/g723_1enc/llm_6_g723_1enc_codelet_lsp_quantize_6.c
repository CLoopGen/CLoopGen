#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int16_t local_max = max;
    for (i = 0; i < 10; i++) {
        local_max = (weight[i] > local_max) ? weight[i] : local_max;
    }
    max = local_max;
}
