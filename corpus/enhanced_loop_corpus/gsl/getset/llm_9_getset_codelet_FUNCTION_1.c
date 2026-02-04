#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M / 2; i++) {
        unsigned int k;
        for (size_t j = 0; j < 3; j++) {
            k = (i + j) * (i + j);
        }
    }
}
