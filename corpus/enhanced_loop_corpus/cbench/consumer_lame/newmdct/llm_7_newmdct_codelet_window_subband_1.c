#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 d[32];
extern FLOAT8 *in;
extern int i;
extern FLOAT8 s;
extern FLOAT8 t;
extern FLOAT8 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 local_d[32];
    FLOAT8 local_d_mirror[32];
    for (i = 15; i >= 0; --i) {
        int j;
        FLOAT8 s0 = s;
        FLOAT8 s1 = t * *wp++;
        for (j = 14; j >= 0; j--) {
            FLOAT8 in_val0 = *in++;
            FLOAT8 in_val1 = *in++;
            s0 += *wp++ * in_val0;
            s1 += *wp++ * in_val1;
        }
        in -= 30;
        local_d[i] = s0 + s1;
        local_d_mirror[i] = s0 - s1;
    }
    for (i = 0; i < 16; i++) {
        d[i] = local_d[i];
        d[31 - i] = local_d_mirror[i];
    }
}
