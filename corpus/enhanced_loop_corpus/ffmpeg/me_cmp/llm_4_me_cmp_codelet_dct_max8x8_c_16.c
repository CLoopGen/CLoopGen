#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int16_t val = temp[i];
        if (val < 0) val = -val;
        if (val > sum) {
            sum = val;
        }
    }
}
