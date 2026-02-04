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

static const char wavelet_name[] = "dummy";
static int dummy_init(const double **a, const double **b, const double **c, const double **d, size_t *e, size_t *f, size_t g) { return 0; }
static const gsl_wavelet_type internal_type = { wavelet_name, dummy_init };

static double *internal_h2;
static double *internal_g2;

gsl_wavelet *w;
double *a;
size_t stride;
size_t n;
gsl_wavelet_workspace *work;
double ai;
double ai1;
size_t i;
size_t ii;
size_t jf;
size_t k;
size_t n1;
size_t ni;
size_t nh;
size_t nmod;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of data (assuming doubles)
    
    a = (double*)aligned_alloc(64, sizeof(double) * data_size);
    work = (gsl_wavelet_workspace*)malloc(sizeof(gsl_wavelet_workspace));
    w = (gsl_wavelet*)malloc(sizeof(gsl_wavelet));

    nh = 16;
    n = data_size / nh; // ensure we have enough data
    stride = 1;
    nmod = 0;
    n1 = n - 1;

    internal_h2 = (double*)aligned_alloc(64, sizeof(double) * nh);
    internal_g2 = (double*)aligned_alloc(64, sizeof(double) * nh);
    for (size_t idx = 0; idx < nh; idx++) {
        internal_h2[idx] = 1.0 / (idx + 1);
        internal_g2[idx] = -1.0 / (idx + 1);
    }

    w->type = &internal_type;
    w->h1 = NULL;
    w->g1 = NULL;
    w->h2 = internal_h2;
    w->g2 = internal_g2;
    w->nc = nh;
    w->offset = 0;

    work->n = n;
    work->scratch = (double*)aligned_alloc(64, sizeof(double) * n);
    for (size_t idx = 0; idx < n; idx++) {
        work->scratch[idx] = 0.0;
    }

    for (size_t idx = 0; idx < n; idx++) {
        a[idx] = (double)(idx % 1000) / 1000.0;
    }

    ai = 0.0;
    ai1 = 0.0;
    i = 0;
    ii = 0;
    jf = 0;
    k = 0;
    ni = 0;
}