#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t src[];
extern int stride;
extern int y;
extern int min;
extern int max;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < 9; y++) {
        int x;
        p = src + stride * y + 1;
        uint8_t local_min = *p;
        uint8_t local_max = *p;
        for (x = 1; x < 9; x++) {
            p++;
            if (*p > local_max)
                local_max = *p;
            if (*p < local_min)
                local_min = *p;
        }
        if (local_max > max)
            max = local_max;
        if (local_min < min)
            min = local_min;
    }
}
