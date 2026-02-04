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
    FLOAT8 local_en[3] = {en[0], en[1], en[2]};
    int idx = 0;
    for (j = 0; j < 192; j++) {
        for (b = 0; b < 3; b++) {
            local_en[b] += xr[idx] * xr[idx];
            idx++;
        }
    }
    en[0] = local_en[0];
    en[1] = local_en[1];
    en[2] = local_en[2];
}
