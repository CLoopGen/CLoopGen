#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        int16_t val = dst[i];
        int32_t temp = val > 30189 ? 30189 : val;
        temp = temp * 19077;
        temp = temp - 39057361;
        temp = temp >> 14;
        dst[i] = (int16_t)temp;
        for (j = 0; j < 2; j++) {
            temp = (temp * 15000 - 20000000) >> 12;
        }
    }
}
