#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    const char *name;
    int (*init)(const double **, const double **, const double **, const double **, size_t *, size_t *, size_t);
} gsl_wavelet_type;

typedef struct {
    const gsl_wavelet_type *type;
    const double *h1;
    const double *g1;
    const double *h2;
    const double *g2;
    size_t nc;
    size_t offset;
} gsl_wavelet;

typedef struct {
    double *scratch;
    size_t n;
} gsl_wavelet_workspace;

extern  gsl_wavelet *w;
extern double *a;
extern size_t stride;
extern size_t n;
extern gsl_wavelet_workspace *work;
extern double ai;
extern double ai1;
extern size_t i;
extern size_t ii;
extern size_t jf;
extern size_t k;
extern size_t n1;
extern size_t ni;
extern size_t nh;
extern size_t nmod;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ii = 0 , i = 0; i < n; i += 2 , ii++) {
    ai = ((a)[(stride) * (ii)]);
    ai1 = ((a)[(stride) * (ii + nh)]);
    ni = i + nmod;
    for (k = 0; k < w->nc; k++) {
        jf = (n1 & (ni + k));
        work->scratch[jf] += (w->h2[k] * ai + w->g2[k] * ai1);
    }
}

}
