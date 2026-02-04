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
    // Variant 2: Strided memory access with reverse traversal of the outer loop to test different access patterns
    // Also reorders computation to access scratch in increasing jf order when possible

    size_t temp_jf;
    const double *h2_cache = w->h2;
    const double *g2_cache = w->g2;

    // Traverse from the end to beginning with same step size
    for (ii = (n / 2) - 1, i = n - 2; i < n; i -= 2, ii--) {
        ai = a[stride * ii];
        ai1 = a[stride * (ii + nh)];
        ni = i + nmod;

        // Inner loop remains forward but uses cached pointers
        for (k = 0; k < w->nc; k++) {
            temp_jf = (n1 & (ni + k));
            work->scratch[temp_jf] += (h2_cache[k] * ai + g2_cache[k] * ai1);
        }

        if (ii == 0) break; // Prevent underflow since ii is unsigned
    }
}
