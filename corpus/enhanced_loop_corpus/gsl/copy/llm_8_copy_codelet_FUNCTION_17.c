#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        for (j = 0; j < i; j++) {
            volatile size_t x = j * i + j % (i + 1);
        }
    }
}
