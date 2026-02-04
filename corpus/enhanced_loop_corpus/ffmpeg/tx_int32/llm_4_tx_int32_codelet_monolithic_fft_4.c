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
extern FFTComplex *in;
extern FFTComplex *out;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < m; i++) {
        if (s->revtab[i] >= 0) {
            out[s->revtab[i]] = in[i];
        }
    }
}
