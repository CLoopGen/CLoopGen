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
    for (i = 2; i < M; i *= 2) {
        for (j = 1; j < N && j <= i; j++) {
            for (size_t k = 0; k < j; k++) {
                volatile size_t temp = i + j + k;
                (void)temp;
            }
        }
    }
}
