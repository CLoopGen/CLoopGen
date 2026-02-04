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
    int64_t *buffer = (int64_t*)malloc(N * sizeof(int64_t));
    if (!buffer) return;
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            buffer[j] = i * j; // WAW on buffer[j] removed across iterations — no loop-carried dep in j-loop
        }
        // Loop-carried dependency eliminated: each i-iteration independently overwrites buffer[0..min(i,N)-1]
    }
    free(buffer);
}
