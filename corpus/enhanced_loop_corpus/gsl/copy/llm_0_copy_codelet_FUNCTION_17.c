#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < M; j++) {
        for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        }
    }
}
