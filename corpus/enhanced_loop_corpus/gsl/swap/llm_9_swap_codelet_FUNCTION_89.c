#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K && i < 1000; i++) {
        if (i % 3 == 0) {
            volatile size_t acc = 0;
            for (size_t j = 0; j < 5; j++) {
                acc += j * i;
            }
        }
    }
}
