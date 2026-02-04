#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP923879532;
E KP382683432;
E KP707106781;
INT m;

#define N 65536  // Size of the data (tuned to run ~0.01s)

static R Rp_data[N];
static R Ip_data[N];
static R Rm_data[N];
static R Im_data[N];
static R W_data[30 * (N + 1)];  // W has 30 elements per iteration, offset by (mb-1)*30
static INT rs_data[8];          // rs[7] is accessed, so need at least 8 elements

void init_vars() {
    // Initialize constants
    KP923879532 = 0.923879532f;
    KP382683432 = 0.382683432f;
    KP707106781 = 0.707106781f;

    // Set array pointers
    Rp = Rp_data;
    Ip = Ip_data;
    Rm = Rm_data;
    Im = Im_data;
    W = W_data;
    rs = rs_data;

    // Set loop parameters
    ms = 1;           // stride step
    mb = 1;           // start index
    me = N - 7;       // ensure all pointer accesses (e.g., rs[7], rp[7]) are in bounds

    // Initialize rs strides: make sure rs[i] offsets stay within [0, N-1]
    for (INT i = 0; i < 8; ++i) {
        rs_data[i] = i * 1;  // linear strides
    }

    // Initialize data arrays with non-zero values for meaningful computation
    for (INT i = 0; i < N; ++i) {
        Rp_data[i] = sin(i * 0.1);
        Ip_data[i] = cos(i * 0.1);
        Rm_data[i] = sin(i * 0.2);
        Im_data[i] = cos(i * 0.2);
    }

    // Initialize W: 30 coefficients per m, starting from offset (mb - 1)*30 = 0
    for (INT i = 0; i < 30 * (N + 1); ++i) {
        W_data[i] = sin(i * 0.05) * 0.9 + 0.1;
    }
}