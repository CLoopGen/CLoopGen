#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef int INTFLOAT;

int NR_PAR_BANDS[2] = {64, 128};
int is34 = 0;
INTFLOAT *peak_decay_nrg;
INTFLOAT *peak_decay_diff_smooth;
int i;
int n;
int n0 = 0;
int nL;
INTFLOAT peak_decay_factor = 1610612736; // fixed-point factor ~0.75

void init_vars() {
    const size_t data_size = 134217728; // ~128MB of input data
    const int total_bands = NR_PAR_BANDS[is34];
    
    nL = (data_size / sizeof(INTFLOAT)) / total_bands;
    if (nL == 0) nL = 1;

    size_t array_size = (size_t)total_bands * (size_t)nL;
    if (array_size == 0) array_size = 1;

    peak_decay_nrg = (INTFLOAT*)calloc(array_size, sizeof(INTFLOAT));
    peak_decay_diff_smooth = (INTFLOAT*)calloc(array_size, sizeof(INTFLOAT));

    if (!peak_decay_nrg || !peak_decay_diff_smooth) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < array_size; idx++) {
        peak_decay_nrg[idx] = (INTFLOAT)(rand() % 1000 + 1);
        peak_decay_diff_smooth[idx] = (INTFLOAT)(rand() % 2);
    }
}