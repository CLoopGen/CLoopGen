#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int16_t temp[2];
    for (k = 4; k < 6; k++) {
        temp[k - 4] = index[k];
        if (temp[k - 4] >= 44 && temp[k - 4] < 108) {
            index[k] = temp[k - 4] + 64;
        } else if (temp[k - 4] >= 108 && temp[k - 4] < 128) {
            index[k] = temp[k - 4] + 128;
        }
    }
}
