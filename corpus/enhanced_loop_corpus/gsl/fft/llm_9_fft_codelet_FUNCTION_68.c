#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k1 = 0; k1 < q && k1 < 1000; k1++) {
        for (size_t j = 0; j < 5; j++) {
            volatile size_t temp = (k1 + j) * (k1 - j);
        }
    }
}
