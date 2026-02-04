#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K && i < 1000; i += 2) {
        if (i % 4 == 0) {
            volatile size_t z = i * 3 + 5;
        }
    }
}
