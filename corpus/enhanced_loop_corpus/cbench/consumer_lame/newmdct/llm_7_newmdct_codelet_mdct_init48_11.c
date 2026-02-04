#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 accumulator = 0.0;
    for (k = 6; k >= 0; k--) {
        accumulator += *wp;
        *wr = (*wp / max) + accumulator;
        wr++;
        wp++;
    }
}
