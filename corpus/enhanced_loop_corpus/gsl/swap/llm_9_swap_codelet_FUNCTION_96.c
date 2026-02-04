#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K && i < 1000; i++) {
        size_t j;
        for (j = 0; j < (K > 50 ? 50 : K); j++) {
            volatile size_t dummy = (i * j) % 1024;
        }
    }
}
