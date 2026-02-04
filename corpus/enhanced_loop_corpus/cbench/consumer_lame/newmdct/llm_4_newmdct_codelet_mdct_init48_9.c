#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int i;
extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 mmax[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 14; i >= 0; --i) {
    FLOAT8 w = *wp++;
    if (w <= 0.0) continue;
    mmax[i] = mmax[30 - i] = w / max;
    for (k = 0; k < 15; k++) {
        *wr++ = *wp++ / w;
    }
}
}
