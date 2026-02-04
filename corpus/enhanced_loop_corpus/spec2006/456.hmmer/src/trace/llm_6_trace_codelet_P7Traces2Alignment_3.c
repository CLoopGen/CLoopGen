#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= mlen; i++) {
        inserts[i] = 0;
        if (i > 0)
            inserts[i] += inserts[i-1]; // Introduces RAW and loop-carried dependency (WAW via cumulative effect)
    }
}
