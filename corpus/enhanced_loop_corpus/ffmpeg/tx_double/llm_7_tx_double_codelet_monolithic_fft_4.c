#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexDouble {
    double re;
    double im;
} AVComplexDouble;

typedef AVComplexDouble FFTComplex;

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
        out[s->revtab[i]].re = in[i].re;
        out[s->revtab[i]].im = in[i].im;
    }
}
