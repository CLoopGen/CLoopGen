#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef double npy_longdouble;

char *ip1;
npy_intp is1;
char *ip2;
npy_intp is2;
npy_intp n;
npy_longdouble tmpr;
npy_longdouble tmpi;
npy_intp i;

static npy_longdouble *data1 = NULL;
static npy_longdouble *data2 = NULL;

void init_vars() {
    const size_t element_size = 2 * sizeof(npy_longdouble);
    const size_t total_bytes = 64 * 1024 * 1024;
    n = total_bytes / element_size;
    if (n == 0) n = 1;

    data1 = (npy_longdouble *)aligned_alloc(64, n * element_size);
    data2 = (npy_longdouble *)aligned_alloc(64, n * element_size);

    for (npy_intp j = 0; j < n; j++) {
        data1[j * 2 + 0] = (npy_longdouble)(j % 1000) / 100.0;
        data1[j * 2 + 1] = (npy_longdouble)((j + 1) % 1000) / 100.0;
        data2[j * 2 + 0] = (npy_longdouble)((j + 2) % 1000) / 100.0;
        data2[j * 2 + 1] = (npy_longdouble)((j + 3) % 1000) / 100.0;
    }

    ip1 = (char *)data1;
    ip2 = (char *)data2;
    is1 = element_size;
    is2 = element_size;
    tmpr = 0.0;
    tmpi = 0.0;
    i = 0;
}