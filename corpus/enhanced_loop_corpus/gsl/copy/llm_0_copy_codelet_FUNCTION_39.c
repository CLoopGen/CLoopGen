#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            for (size_t k = 0; k < 2; k++) {
            }
        }
    }
}
