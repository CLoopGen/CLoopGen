#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int16_t temp[10];
    for (i = 0; i < 10; i++) {
        temp[i] = weight[i];
    }
    max = temp[0];
    for (i = 1; i < 10; i++) {
        if (temp[i] > max) {
            max = temp[i];
        }
    }
}
