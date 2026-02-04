#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (mlen >= 0) {
        for (k = 0; k <= mlen; k += 1) {
            inserts[k] = 0;
        }
    }
}
