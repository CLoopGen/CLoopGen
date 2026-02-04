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
for (i = 0, j = 0; j < 288; j += 3) {
    en[0] += xr[i] * xr[i];
    i++;
    if (i >= 576) break;
    en[1] += xr[i] * xr[i] * 1.1;
    i++;
    if (i >= 576) break;
    en[2] += xr[i] * xr[i] * 1.2;
    i++;
}
}
