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
    for (i = 15; i >= 0; --i) {
        int j;
        FLOAT8 s0 = s;
        FLOAT8 s1 = t * wp[0];
        FLOAT8 temp_sum0 = 0.0;
        FLOAT8 temp_sum1 = 0.0;
        for (j = 14; j >= 0; j--) {
            temp_sum0 += wp[2*j + 1] * in[2*j];
            temp_sum1 += wp[2*j + 2] * in[2*j + 1];
        }
        s0 += temp_sum0;
        s1 += temp_sum1;
        in -= 30;
        d[i] = s0 + s1;
        d[31 - i] = s0 - s1;
    }
}
