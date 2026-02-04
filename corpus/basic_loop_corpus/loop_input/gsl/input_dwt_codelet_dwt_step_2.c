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
static int dummy_init(const double **, const double **, const double **, const double **, size_t *, size_t *, size_t) { return 0; }
static const gsl_wavelet_type internal_type = { wavelet_name, dummy_init };

static double *a_data;
static double *scratch_data;
static double *h1_data;
static double *g1_data;

gsl_wavelet *w;
double *a;
size_t stride;
size_t n;
gsl_wavelet_workspace *work;
size_t i;
size_t ii;
size_t jf;
size_t k;
size_t n1;
size_t ni;
size_t nh;
size_t nmod;

void init_vars() {
    n = (1 << 20);  // 1M elements, approx. 8MB of data
    stride = 1;
    nh = n / 2;
    nmod = n - 1;
    n1 = n - 1;

    a_data = (double*)calloc(n, sizeof(double));
    scratch_data = (double*)calloc(n, sizeof(double));
    h1_data = (double*)malloc(sizeof(double) * 32);
    g1_data = (double*)malloc(sizeof(double) * 32);

    if (!a_data || !scratch_data || !h1_data || !g1_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        a_data[idx] = 1.0;
    }
    for (size_t idx = 0; idx < 32; idx++) {
        h1_data[idx] = 1.0 / (idx + 1);
        g1_data[idx] = -1.0 / (idx + 1);
    }

    w = (gsl_wavelet*)malloc(sizeof(gsl_wavelet));
    work = (gsl_wavelet_workspace*)malloc(sizeof(gsl_wavelet_workspace));
    if (!w || !work) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    w->type = &internal_type;
    w->h1 = h1_data;
    w->g1 = g1_data;
    w->h2 = NULL;
    w->g2 = NULL;
    w->nc = 16;  // Must be <= 32 to avoid buffer overflow
    w->offset = 0;

    work->scratch = scratch_data;
    work->n = n;

    a = a_data;
    i = 0;
    ii = 0;
    jf = 0;
    k = 0;
    ni = 0;
    nh = n / 2;
    nmod = n - 1;
}

// Ensure symbols are defined
void loop();