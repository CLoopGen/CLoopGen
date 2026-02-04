#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < q && k1 < 1000; k1 += 2) {
        size_t sum = 0;
        for (size_t j = 0; j < k1; j++) {
            sum += j * j;
        }
    }
}
