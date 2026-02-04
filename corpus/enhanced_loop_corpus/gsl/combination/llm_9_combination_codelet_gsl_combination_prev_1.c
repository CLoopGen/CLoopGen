#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (k + 3) / 4 * 4; // Round up to nearest multiple of 4
    for (; i < limit; i++) {
        if (i < k) {
            data[i] = n - k + i;
        }
    }
}
