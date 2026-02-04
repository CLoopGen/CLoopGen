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
    if (j >= N / 2) {
        for (j = 0; j < N; j += 2) {
        }
    } else {
        for (j = 0; j < N; j++) {
        }
    }
}
}
