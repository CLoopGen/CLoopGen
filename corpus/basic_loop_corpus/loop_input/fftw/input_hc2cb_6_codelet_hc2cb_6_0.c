#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386;
INT m;

void init_vars(void)
{
    const size_t N = 1 << 20; // ~16 million elements, adjust for ~0.01s runtime
    const INT vector_width = 3;
    const INT padding = 16;

    Rp = (R*)aligned_alloc(32, sizeof(R) * (N + padding));
    Ip = (R*)aligned_alloc(32, sizeof(R) * (N + padding));
    Rm = (R*)aligned_alloc(32, sizeof(R) * (N + padding));
    Im = (R*)aligned_alloc(32, sizeof(R) * (N + padding));
    W = (R*)aligned_alloc(32, sizeof(R) * 10 * (N + padding));

    rs = (INT*)aligned_alloc(32, sizeof(INT) * 3);
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    ms = 1;
    mb = 1;
    me = N - 2;

    for (size_t i = 0; i < N + padding; ++i) {
        Rp[i] = (R)(rand() % 100) / 100.0;
        Ip[i] = (R)(rand() % 100) / 100.0;
        Rm[i] = (R)(rand() % 100) / 100.0;
        Im[i] = (R)(rand() % 100) / 100.0;
    }

    for (size_t i = 0; i < 10 * (N + padding); ++i) {
        W[i] = (R)(rand() % 100) / 100.0;
    }
}