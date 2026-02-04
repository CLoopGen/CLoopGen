#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max1 = max;
    int temp_max2 = max;
    for (i = 0; i < 10; i += 2) {
        temp_max1 = (weight[i] > temp_max1) ? weight[i] : temp_max1;
        if (i + 1 < 10) {
            temp_max2 = (weight[i + 1] > temp_max2) ? weight[i + 1] : temp_max2;
        }
    }
    max = (temp_max1 > temp_max2) ? temp_max1 : temp_max2;
}
