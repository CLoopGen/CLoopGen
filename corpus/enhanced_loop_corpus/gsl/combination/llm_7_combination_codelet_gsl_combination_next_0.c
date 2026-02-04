#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t k;
extern size_t *data;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < k - 1; j += 2) {
        if (j + 1 < k - 1) {
            data[j + 1] = data[j] + 1;
            data[j + 2] = data[j + 1] + 1;
        } else {
            data[j + 1] = data[j] + 1;
        }
    }
}
