#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= mlen; i += 2) {
        if (inserts[i] > 1)
            inserts[i] = 1;
        if (i + 1 <= mlen && inserts[i + 1] > 1)
            inserts[i + 1] = 1;
    }
}
