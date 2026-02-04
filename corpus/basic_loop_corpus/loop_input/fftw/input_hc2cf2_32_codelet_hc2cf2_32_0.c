#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Define data size to achieve ~0.01 seconds runtime
// Empirical tuning: use N ≈ 2^18 for reasonable performance
#define N (1 << 18)
#define DATA_SIZE (N * sizeof(double))

// Allocate large arrays
static double *Rp_data = NULL;
static double *Ip_data = NULL;
static double *Rm_data = NULL;
static double *Im_data = NULL;
static double *W_data = NULL;
static INT *rs_data = NULL;

// Global pointers
R *Rp = NULL;
R *Ip = NULL;
R *Rm = NULL;
R *Im = NULL;
R *W = NULL;
stride rs = NULL;

// Loop bounds and step
INT mb = 1;
INT me = N + 1;  // ensures m < me covers [1, N]
INT ms = 1;

// Constants used in computation
E KP195090322 = 0.195090322;
E KP980785280 = 0.980785280;
E KP555570233 = 0.555570233;
E KP831469612 = 0.831469612;
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;

INT m = 0;

void init_vars() {
    // Allocate memory
    Rp_data = (double*)calloc(N, sizeof(double));
    Ip_data = (double*)calloc(N, sizeof(double));
    Rm_data = (double*)calloc(N, sizeof(double));
    Im_data = (double*)calloc(N, sizeof(double));
    W_data = (double*)malloc(8 * N * sizeof(double));
    rs_data = (INT*)malloc(N * sizeof(INT));

    if (!Rp_data || !Ip_data || !Rm_data || !Im_data || !W_data || !rs_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize rs: set all strides to 1 for contiguous access
    for (INT i = 0; i < N; ++i) {
        rs_data[i] = 1;
    }

    // Initialize twiddle factors W
    for (INT i = 1; i <= N; ++i) {
        double angle = 2.0 * M_PI * (i - 1) / N;
        W_data[(i-1)*8 + 0] = cos(angle * 0); W_data[(i-1)*8 + 1] = sin(angle * 0);
        W_data[(i-1)*8 + 2] = cos(angle * 1); W_data[(i-1)*8 + 3] = sin(angle * 1);
        W_data[(i-1)*8 + 4] = cos(angle * 2); W_data[(i-1)*8 + 5] = sin(angle * 2);
        W_data[(i-1)*8 + 6] = cos(angle * 3); W_data[(i-1)*8 + 7] = sin(angle * 3);
    }

    // Set global pointers
    Rp = Rp_data;
    Ip = Ip_data;
    Rm = Rm_data;
    Im = Im_data;
    W = W_data;
    rs = rs_data;

    // Ensure loop bounds are valid
    mb = 1;
    me = N + 1;
    ms = 1;
}