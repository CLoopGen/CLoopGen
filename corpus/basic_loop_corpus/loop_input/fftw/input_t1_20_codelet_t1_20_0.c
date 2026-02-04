#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP587785252;
E KP951056516;
E KP250000000;
E KP559016994;
INT m;

#define N 131072  // Size chosen to make loop run ~0.01s

static R ri_data[N];
static R ii_data[N];
static R W_data[38 * N];  // Enough space for W + (mb * 38) with margin
static INT rs_data[N];

void init_vars() {
    // Initialize constants
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;
    KP250000000 = 0.250000000;
    KP559016994 = 0.559016994;

    // Set data pointers
    ri = ri_data;
    ii = ii_data;
    W = W_data;
    rs = rs_data;

    // Initialize arrays
    for (INT i = 0; i < N; i++) {
        ri[i] = sin(i);
        ii[i] = cos(i);
        rs[i] = (i * 7) % (N - 1);  // Ensure valid indices
    }

    for (INT i = 0; i < 38 * N; i++) {
        W[i] = sin(i * 0.1);
    }

    // Set loop bounds
    mb = 0;
    me = N / 8;  // Keep within safe bounds considering rs offsets up to 19
    ms = 1;

    // Clamp me to avoid out-of-bounds via rs indexing
    while (me > 0) {
        int valid = 1;
        for (INT idx = mb; idx < me; idx++) {
            if (rs[idx] + 19 >= N || rs[idx] < 0) {
                valid = 0;
                break;
            }
        }
        if (valid) break;
        me--;
    }
}