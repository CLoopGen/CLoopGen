#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

npy_intp is = sizeof(rational);
npy_intp os = sizeof(rational);
npy_intp n = 1000000;
char *i;
char *o;
int k;

static rational *input_data = NULL;
static rational *output_data = NULL;

void init_vars() {
    struct timeval tv_start, tv_end;
    double elapsed_time;
    int estimated_n;
    long long bytes_processed;

    gettimeofday(&tv_start, NULL);

    input_data = (rational *)aligned_alloc(64, n * sizeof(rational));
    output_data = (rational *)aligned_alloc(64, n * sizeof(rational));
    if (!input_data || !output_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (npy_intp idx = 0; idx < n; idx++) {
        input_data[idx].n = idx;
        input_data[idx].dmm = idx + 1;
    }

    i = (char *)input_data;
    o = (char *)output_data;

    gettimeofday(&tv_start, NULL);

    for (k = 0; k < n; k++) {
        rational x = *(rational *)i;
        i += is;
        o += os;
    }

    gettimeofday(&tv_end, NULL);
    elapsed_time = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1e6;

    if (elapsed_time < 0.005 || elapsed_time > 0.02) {
        estimated_n = (int)(n * 0.01 / (elapsed_time > 0 ? elapsed_time : 1e-9));
        estimated_n = estimated_n < 10000 ? 10000 : estimated_n;
        estimated_n = estimated_n > 256 * 1024 * 1024 / sizeof(rational) ? 256 * 1024 * 1024 / sizeof(rational) : estimated_n;

        free(input_data);
        free(output_data);

        n = estimated_n;
        input_data = (rational *)aligned_alloc(64, n * sizeof(rational));
        output_data = (rational *)aligned_alloc(64, n * sizeof(rational));

        if (!input_data || !output_data) {
            fprintf(stderr, "Failed to allocate memory\n");
            exit(1);
        }

        for (npy_intp idx = 0; idx < n; idx++) {
            input_data[idx].n = idx;
            input_data[idx].dmm = idx + 1;
        }

        i = (char *)input_data;
        o = (char *)output_data;
    }
}