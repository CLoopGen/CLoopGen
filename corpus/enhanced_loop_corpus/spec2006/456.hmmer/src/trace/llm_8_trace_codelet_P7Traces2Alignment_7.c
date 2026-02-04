#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < mlen; k += 2) {
        if (k + 1 <= mlen && inserts[k + 1] > 1)
            inserts[k + 1] = 1;
        if (inserts[k] > 1)
            inserts[k] = 1;
    }
    if (mlen >= 0 && k - 1 == mlen && inserts[mlen] > 1)
        inserts[mlen] = 1;
}
