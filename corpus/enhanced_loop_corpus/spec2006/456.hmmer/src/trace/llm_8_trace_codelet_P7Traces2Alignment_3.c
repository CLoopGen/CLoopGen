#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (k = 0; k <= mlen; k += step) {
        inserts[k] = 0;
        if (k + 1 <= mlen) {
            inserts[k + 1] = 0;
        }
    }
}
