#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

double *a;
npy_intp lena;
npy_intp i;
double last;

static double a_data[131072]; // 1MB of data (131072 doubles = ~1.05MB)

void init_vars() {
    lena = 131072;
    a = a_data;
    last = 42.0;

    // Initialize array so that the loop runs for most of the array but stops early
    for (npy_intp j = 0; j < lena - 1; j++) {
        a[j] = last;
    }
    // Set last element to break condition, ensuring loop stops at second-to-last
    a[lena - 1] = last + 1.0;

    i = 1; // Initial value per loop logic
}