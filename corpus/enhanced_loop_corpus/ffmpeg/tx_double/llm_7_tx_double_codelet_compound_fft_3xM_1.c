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
extern  int m;
extern  int *out_map;
extern FFTComplex *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTComplex *tmp = s->tmp;
    for (int i = 0; i < 3 * m; i += 3) {
        out[i] = tmp[out_map[i]];
        if (i + 1 < 3 * m) {
            out[i + 1] = tmp[out_map[i + 1]];
        }
        if (i + 2 < 3 * m) {
            out[i + 2] = tmp[out_map[i + 2]];
        }
    }
}
