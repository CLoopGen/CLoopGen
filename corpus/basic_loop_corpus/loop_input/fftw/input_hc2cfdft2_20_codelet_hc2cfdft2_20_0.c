#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Declare arrays with sufficient size to avoid out-of-bounds access
// Based on the loop using rs indices: rs[1], rs[2], ..., rs[9] -> need at least 10 elements
#define RS_SIZE 10
#define DATA_SIZE (1 << 20)  // ~16 MB of complex data (each R is 8 bytes)

static R *Rp_data;
static R *Ip_data;
static R *Rm_data;
static R *Im_data;
static R *W_data;

stride rs_data;

// External pointers
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;

// Loop control variables
INT mb;
INT me;
INT ms;

// Constants used in computation
E KP125000000 = 1.25e-7;
E KP500000000 = 5.0e-7;
E KP279508497 = 2.79508497e-7;
E KP293892626 = 2.93892626e-7;
E KP475528258 = 4.75528258e-7;

INT m;

void init_vars() {
    // Allocate data arrays
    Rp_data = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    Ip_data = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    Rm_data = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    Im_data = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    W_data = (R*)aligned_alloc(32, 8 * 10 * sizeof(R));  // W accessed up to index 7 per iteration

    if (!Rp_data || !Ip_data || !Rm_data || !Im_data || !W_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data arrays to zero
    memset(Rp_data, 0, DATA_SIZE * sizeof(R));
    memset(Ip_data, 0, DATA_SIZE * sizeof(R));
    memset(Rm_data, 0, DATA_SIZE * sizeof(R));
    memset(Im_data, 0, DATA_SIZE * sizeof(R));
    memset(W_data, 0, 8 * 10 * sizeof(R));

    // Initialize twiddle factors W: each block of 8 values for one m
    for (int i = 0; i < 10; ++i) {
        W_data[i*8 + 0] = cos(i * 0.1);
        W_data[i*8 + 1] = sin(i * 0.1);
        W_data[i*8 + 2] = cos(i * 0.2);
        W_data[i*8 + 3] = sin(i * 0.2);
        W_data[i*8 + 4] = cos(i * 0.3);
        W_data[i*8 + 5] = sin(i * 0.3);
        W_data[i*8 + 6] = cos(i * 0.4);
        W_data[i*8 + 7] = sin(i * 0.4);
    }

    // Allocate and initialize stride array
    rs = rs_data = (INT*)aligned_alloc(32, RS_SIZE * sizeof(INT));
    for (int i = 0; i < RS_SIZE; ++i) {
        rs_data[i] = (i+1) * 100;  // ensure non-zero strides within bounds
    }

    // Set external pointers to base of allocated arrays
    Rp = Rp_data;
    Ip = Ip_data;
    Rm = Rm_data;
    Im = Im_data;
    W = W_data;

    // Set loop bounds
    mb = 1;
    me = 10;  // must be <= number of W blocks available
    ms = 1;   // stride step for pointer updates

    // Ensure that all memory accesses in the loop are within bounds
    // The maximum index used via rs[i] is rs[9], and we access Rp[rs[9]], etc.
    // So we require rs[9] < DATA_SIZE
    for (int i = 0; i < RS_SIZE; ++i) {
        if (rs_data[i] >= DATA_SIZE) rs_data[i] = DATA_SIZE - 1;
    }
}