#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexInt32 {
    int32_t re;
    int32_t im;
} AVComplexInt32;

typedef AVComplexInt32 FFTComplex;

struct AVTXContext {
    int n;
    int m;
    int inv;
    int type;
    FFTComplex *exptab;
    FFTComplex *tmp;
    int *pfatab;
    int *revtab;
};


typedef struct AVTXContext AVTXContext;

extern AVTXContext *s;
extern  int m;
extern  int *out_map;
extern FFTComplex *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 5 * m; i++) {
        int idx1 = out_map[3*i];
        int idx2 = out_map[3*i + 1];
        int idx3 = out_map[3*i + 2];
        out[3*i]     = s->tmp[idx1];
        out[3*i + 1] = s->tmp[idx2];
        out[3*i + 2] = s->tmp[idx3];
    }
}
