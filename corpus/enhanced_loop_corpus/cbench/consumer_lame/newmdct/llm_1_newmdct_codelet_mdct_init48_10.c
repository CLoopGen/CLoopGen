#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 7; k += 2) {
    *wr++ = *wp++ / w;
    if (k + 1 < 7) {
        *wr++ = *wp++ / w;
    }
}
}
