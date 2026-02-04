#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP707106781;
INT m;

static size_t N;

void init_vars() {
    const double PI = 3.14159265358979323846;
    KP707106781 = 0.707106781; // Approximately 1/sqrt(2)

    N = (1 << 20) / sizeof(R); // ~1MB of data per array, adjust as needed

    mb = 1;
    me = N / 4;
    ms = 1;

    size_t total_size = N * sizeof(R);
    Rp = (R*)aligned_alloc(64, total_size);
    Ip = (R*)aligned_alloc(64, total_size);
    Rm = (R*)aligned_alloc(64, total_size);
    Im = (R*)aligned_alloc(64, total_size);
    W = (R*)aligned_alloc(64, (me + 1) * 6 * sizeof(R));

    if (!Rp || !Ip || !Rm || !Im || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rs = (stride)aligned_alloc(64, 4 * sizeof(INT));
    if (!rs) exit(1);
    rs[0] = 0;
    rs[1] = (INT)(N / 4);
    rs[2] = (INT)(N / 2);
    rs[3] = (INT)(3 * N / 4);

    for (size_t i = 0; i < N; ++i) {
        Rp[i] = sin(2.0 * PI * i / N);
        Ip[i] = cos(2.0 * PI * i / N);
        Rm[i] = sin(4.0 * PI * i / N);
        Im[i] = cos(4.0 * PI * i / N);
    }

    for (INT k = 0; k < me + 1; ++k) {
        double angle = 2.0 * PI * k / N;
        W[k*6 + 0] = cos(angle);
        W[k*6 + 1] = sin(angle);
        W[k*6 + 2] = cos(angle * 2);
        W[k*6 + 3] = sin(angle * 2);
        W[k*6 + 4] = cos(angle * 4);
        W[k*6 + 5] = sin(angle * 4);
    }
}