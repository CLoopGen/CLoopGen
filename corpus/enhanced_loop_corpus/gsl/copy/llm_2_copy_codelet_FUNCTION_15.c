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
for (i = 1; i < M; i++) {
    for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
        // Change memory access pattern to strided access by stepping through indices with stride of 2
        // Simulated via index manipulation (assuming some array 'A' is being accessed)
        size_t idx = j * 2;
        // Dummy operation to represent memory access
        __asm__ volatile("" : "+g" (idx));
    }
}
}
