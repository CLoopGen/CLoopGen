#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= mlen; k += 2) {  // Decreased effective depth: unroll logic by processing two elements per iteration
        if (inserts[k] > 1)
            inserts[k] = 1;
        if (k + 1 <= mlen && inserts[k + 1] > 1)
            inserts[k + 1] = 1;
    }
}
