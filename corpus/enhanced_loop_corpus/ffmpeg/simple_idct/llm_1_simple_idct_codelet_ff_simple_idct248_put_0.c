#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 8; j++) {
                int a0, a1;
                a0 = ptr[j];
                a1 = ptr[8 + j];
                ptr[j] = a0 + a1;
                ptr[8 + j] = a0 - a1;
            }
            ptr += 2 * 8;
        }
    }
}
