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
    for (j = i + 1; j < N; j += 2) {
        // Strided memory access: simulate accessing every second element
        // Example: if array A were accessed, it would be A[j*stride] or similar
    }
}
}
