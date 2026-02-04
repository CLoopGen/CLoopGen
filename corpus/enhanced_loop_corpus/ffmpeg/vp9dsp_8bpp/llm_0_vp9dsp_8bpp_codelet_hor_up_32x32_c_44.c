#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 32 - 2; i++) {
            v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
            v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        }
    }
}
