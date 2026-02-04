#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern uint32_t lace_size[256];
extern int *laces;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (*laces > 256) ? 256 : *laces;
    for (n = 0; n < limit; n += 2) {
        if (n < limit) {
            lace_size[n] = size / (*laces + 1);
        }
        if (n + 1 < limit) {
            lace_size[n + 1] = (size * 3) / (*laces + 1);
        }
    }
}
