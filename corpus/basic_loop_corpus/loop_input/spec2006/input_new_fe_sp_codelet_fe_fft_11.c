#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

complex *in;
int N;
int s;
complex *from;
double divisor;

void init_vars() {
    N = 1 << 24; // Approximately 256MB of data (each complex is 16 bytes, so 2^24 elements = 256MB)
    in = (complex *)calloc(N, sizeof(complex));
    from = (complex *)calloc(N, sizeof(complex));
    divisor = 2.0;

    for (int i = 0; i < N; i++) {
        in[i].r = (double)(i % 1000) + 1.0;
        in[i].i = (double)(i % 1000) - 1.0;
    }
}