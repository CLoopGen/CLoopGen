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
    volatile uint64_t temp;
    for (i = 0; i < M; i++) {
        temp = i * N; // Break potential WAW/RAW across outer iterations by using volatile
        for (j = 0; j < N; j++) {
            temp = (temp ^ j) + 1; // Create intra-loop dependency (RAW): each j update depends on prior temp
        }
        // No loop-carried dependency across i iterations except through temp, which is reinitialized
    }
}
