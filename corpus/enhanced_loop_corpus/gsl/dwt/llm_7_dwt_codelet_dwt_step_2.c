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
    double *scratch_base = work->scratch;
    const double *a_base = a;
    const double *h1_base = w->h1;
    const double *g1_base = w->g1;
    size_t stride_local = stride;
    size_t n1_local = n1;
    size_t nmod_local = nmod;
    size_t nh_local = nh;

    for (ii = 0, i = 0; i < n; i += 2, ii++) {
        double h = 0.0, g = 0.0;
        size_t ni_local = i + nmod_local;
        size_t unroll_factor = (w->nc >= 4) ? 4 : 1;
        k = 0;

        if (w->nc >= 4) {
            for (; k <= w->nc - unroll_factor; k += unroll_factor) {
                size_t jf0 = n1_local & (ni_local + k + 0);
                size_t jf1 = n1_local & (ni_local + k + 1);
                size_t jf2 = n1_local & (ni_local + k + 2);
                size_t jf3 = n1_local & (ni_local + k + 3);

                h += h1_base[k + 0] * a_base[stride_local * jf0] +
                     h1_base[k + 1] * a_base[stride_local * jf1] +
                     h1_base[k + 2] * a_base[stride_local * jf2] +
                     h1_base[k + 3] * a_base[stride_local * jf3];

                g += g1_base[k + 0] * a_base[stride_local * jf0] +
                     g1_base[k + 1] * a_base[stride_local * jf1] +
                     g1_base[k + 2] * a_base[stride_local * jf2] +
                     g1_base[k + 3] * a_base[stride_local * jf3];
            }
        }

        for (; k < w->nc; k++) {
            size_t jf = n1_local & (ni_local + k);
            h += h1_base[k] * a_base[stride_local * jf];
            g += g1_base[k] * a_base[stride_local * jf];
        }

        scratch_base[ii] += h;
        scratch_base[ii + nh_local] += g;
    }
}
