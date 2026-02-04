#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= mlen; i++) {
        if (inserts[i] > 1) {
            inserts[i] = 1;
        }
        k = i; // Eliminate loop-carried dependency on k; update k only at end of iteration
    }
    // k now carries final value of i, maintaining original post-loop state
}
