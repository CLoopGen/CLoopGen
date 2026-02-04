#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i += stride) {
        // Strided memory access pattern: processing every 'stride'-th element
        // This could correspond to accessing arr[i * stride] in a real use case
    }
}
