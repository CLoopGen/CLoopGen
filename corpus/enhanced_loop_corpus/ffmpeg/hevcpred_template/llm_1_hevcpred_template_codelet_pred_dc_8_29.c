#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint8_t *top;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i1, i2;
    int factor = 4;
    int reduced_size = (size + factor - 1) / factor;
    for (i1 = 0; i1 < reduced_size; i1++) {
        for (i2 = 0; i2 < factor; i2++) {
            int idx = i1 * factor + i2;
            if (idx < size) {
                dc += left[idx] + top[idx];
            }
        }
    }
}
