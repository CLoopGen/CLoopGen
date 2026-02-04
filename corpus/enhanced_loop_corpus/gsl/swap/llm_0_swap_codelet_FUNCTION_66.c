#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j++) {
            for (size_t k = 0; k < j; k++) {
            }
        }
    }
}
