#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

char *ip1;
npy_intp is1;
char *ip2;
npy_intp is2;
npy_intp n;
double sumr;
double sumi;
npy_intp i;

static double *data1;
static double *data2;

void init_vars() {
    const size_t data_size = 1 << 26; // ~128MB of total data, suitable for ~0.01s runtime
    n = data_size / (2 * sizeof(double)); // number of complex pairs

    is1 = 2 * sizeof(double);
    is2 = 2 * sizeof(double);

    data1 = (double*)aligned_alloc(32, data_size);
    data2 = (double*)aligned_alloc(32, data_size);

    if (!data1 || !data2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (npy_intp j = 0; j < 2 * n; j++) {
        data1[j] = (double)(j % 123);
        data2[j] = (double)(j % 456);
    }

    ip1 = (char*)data1;
    ip2 = (char*)data2;

    sumr = 0.0;
    sumi = 0.0;
    i = 0;
}