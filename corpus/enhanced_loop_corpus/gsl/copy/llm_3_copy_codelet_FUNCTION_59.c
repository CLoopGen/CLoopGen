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
    for (i = 0; i < M && M > 0; i++) {
        for (j = i + 1; j < N && j > 0; j++) {
            if (i % 2 == 0) {
                break; // Introduces control dependency: odd i values run loop normally, even i causes early exit of inner loop
            }
        }
    }
}
