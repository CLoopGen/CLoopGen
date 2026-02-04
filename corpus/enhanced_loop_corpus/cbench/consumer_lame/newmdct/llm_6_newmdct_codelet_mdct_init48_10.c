#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp;
    for (k = 0; k < 7; k++) {
        temp = *wp / w;
        *wr = temp;
        wp++;
        wr++;
    }
}
