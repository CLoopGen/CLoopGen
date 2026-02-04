#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (k = 1; k <= mlen; k++) {
        temp = inserts[k - 1]; // Introduce RAW dependency: read before write
        if (inserts[k] > 1) {
            inserts[k] = temp; // WAW dependency with previous iteration via inserts[k]
        }
    }
}
