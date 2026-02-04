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
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(R))

void init_vars() {
    KP382683432 = sin(M_PI / 8);
    KP707106781 = sin(M_PI / 4);
    KP923879532 = sin(3 * M_PI / 8);

    ms = 1;
    mb = 1;
    me = TOTAL_ELEMENTS / 8 - 1;

    size_t total_size = TOTAL_ELEMENTS * sizeof(R);
    Rp = (R*)aligned_alloc(64, total_size);
    Ip = (R*)aligned_alloc(64, total_size);
    Rm = (R*)aligned_alloc(64, total_size);
    Im = (R*)aligned_alloc(64, total_size);
    W = (R*)aligned_alloc(64, total_size);

    rs = (stride)malloc(sizeof(INT));
    rs[0] = 1;

    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        Rp[i] = (R)(rand() % 1000) / 100.0;
        Ip[i] = (R)(rand() % 1000) / 100.0;
        Rm[i] = (R)(rand() % 1000) / 100.0;
        Im[i] = (R)(rand() % 1000) / 100.0;
        W[i] = (R)(rand() % 1000) / 100.0;
    }
}