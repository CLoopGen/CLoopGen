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
int indices[30];
for (int idx = 0; idx < 30; idx++) {
    indices[idx] = idx;
}
for (i = 15; i >= 0; --i) {
    int j;
    FLOAT8 s0 = s;
    FLOAT8 s1 = t * wp[indices[0]];
    for (j = 14; j >= 0; j--) {
        int idx1 = indices[2*j + 1];
        int idx2 = indices[2*j + 2];
        int idx_in1 = indices[2*j];
        int idx_in2 = indices[2*j + 1];
        s0 += wp[idx1] * in[idx_in1];
        s1 += wp[idx2] * in[idx_in2];
    }
    in += 30;
    wp += 30;
    d[i] = s0 + s1;
    d[31 - i] = s0 - s1;
}
}
