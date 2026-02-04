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
    size_t j = i;
    for (; j < k; j += 2) {
        data[j] = n - k + j;
        if (j + 1 < k) {
            data[j + 1] = n - k + j + 1;
        }
    }
    i = j;
}
