#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *Aj;
extern int *Ap;
extern int *ATj;
extern int *w;
extern int p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern on ATj
    // Instead of writing ATj[k] = i sequentially, we write with a fixed stride (e.g., stride of 2)
    // We assume sufficient allocation size for ATj to avoid out-of-bounds
    for (i = 0; i < M; ++i) {
        for (p = Ap[i]; p < Ap[i + 1]; ++p) {
            size_t k = w[Aj[p]]++;
            ATj[2 * k] = i;  // Strided access: write every second element
        }
    }
}
