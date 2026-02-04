#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 xr[576];
extern int i;
extern int j;
extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, j = 0; j < 192; j++) {
    en[0] += xr[i] * xr[i];
    en[1] += xr[i+1] * xr[i+1];
    en[2] += xr[i+2] * xr[i+2];
    i += 3;
}
}
