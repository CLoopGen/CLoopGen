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
    for (size_t j = 0; j < k; j++) {
        for (size_t i_inner = 0; i_inner < 1; i_inner++) {
            data[j] = n - k + j;
        }
    }
}
