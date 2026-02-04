#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_acc = 0;
    for (y = 0; y < 16; y++) {
        int row_sum = 0;
        for (x = 0; x < 16; x++) {
            int diff = src[x + y * stride] - ref;
            row_sum += (diff >= 0) ? diff : -diff;
        }
        temp_acc += row_sum;
    }
    acc = temp_acc;
}
