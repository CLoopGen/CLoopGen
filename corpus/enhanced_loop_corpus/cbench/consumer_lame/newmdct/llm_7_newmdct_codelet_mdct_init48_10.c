#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 local_wr[7];
    for (k = 0; k < 7; k++) {
        local_wr[k] = wp[k] / w;
    }
    for (k = 0; k < 7; k++) {
        wr[k] = local_wr[k];
    }
}
