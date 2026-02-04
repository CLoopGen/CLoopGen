#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 3; k++) {
    FLOAT8 temp1 = *wp++;
    FLOAT8 temp2 = *wp++;
    *wr++ = temp1 / max;
    *wr++ = temp2 / max;
    *wr++ = (temp1 + temp2) * 0.5 / max;
}
}
