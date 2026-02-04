#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < mlen * 2; k++) {
        if (k < mlen + 1) {
            inserts[k] = 0;
        }
    }
}
