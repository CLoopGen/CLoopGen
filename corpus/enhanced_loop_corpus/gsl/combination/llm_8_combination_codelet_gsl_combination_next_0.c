#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < k - 1; i += 2) {
        data[i + 1] = data[i] + 1;
        if (i + 2 < k - 1) {
            data[i + 2] = data[i + 1] + 1;
        }
    }
}
