#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int min;
extern int max;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_min = min;
    int temp_max = max;
    for (y = 1; y < 9; y++) {
        int x;
        for (x = 1; x < 9; x++) {
            p++;
            temp_max = (*p > temp_max) ? *p : temp_max;
            temp_min = (*p < temp_min) ? *p : temp_min;
        }
    }
    max = temp_max;
    min = temp_min;
}
