#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= mlen; k++) {
        inserts[k] = (inserts[k] > 1) ? 1 : inserts[k];
    }
}
