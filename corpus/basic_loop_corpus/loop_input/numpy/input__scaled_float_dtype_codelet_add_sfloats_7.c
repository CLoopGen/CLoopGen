#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp strides[3];
double fact1;
double fact2;
npy_intp N;
char *in1;
char *in2;
char *out;

static double in1_data[65536];
static double in2_data[65536];
static double out_data[65536];

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_sec ^ tv.tv_usec));

    fact1 = 1.5;
    fact2 = 2.5;

    N = 65536;

    strides[0] = sizeof(double);
    strides[1] = sizeof(double);
    strides[2] = sizeof(double);

    in1 = (char *)in1_data;
    in2 = (char *)in2_data;
    out = (char *)out_data;

    for (npy_intp i = 0; i < N; i++) {
        in1_data[i] = (double)(rand() % 1000) / 10.0;
        in2_data[i] = (double)(rand() % 1000) / 10.0;
    }
}