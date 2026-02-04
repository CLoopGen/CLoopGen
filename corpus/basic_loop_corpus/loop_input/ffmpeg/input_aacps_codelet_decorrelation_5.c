#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

typedef float INTFLOAT;

int NR_PAR_BANDS[2] = {32, 32};
int is34 = 0;

INTFLOAT (*power)[32];
INTFLOAT (*transient_gain)[32];
INTFLOAT *peak_decay_nrg;
INTFLOAT *power_smooth;
INTFLOAT *peak_decay_diff_smooth;

float transient_impact = 0.8f;
float a_smooth = 0.1f;
int i;
int n;
int n0;
int nL;
INTFLOAT peak_decay_factor = 0.95f;

void init_vars() {
    n0 = 0;
    nL = 32;

    size_t total_bands = NR_PAR_BANDS[is34];
    size_t total_elements = total_bands * nL;

    power = calloc(total_elements, sizeof(INTFLOAT));
    transient_gain = calloc(total_elements, sizeof(INTFLOAT));
    peak_decay_nrg = calloc(total_bands, sizeof(INTFLOAT));
    power_smooth = calloc(total_bands, sizeof(INTFLOAT));
    peak_decay_diff_smooth = calloc(total_bands, sizeof(INTFLOAT));

    for (size_t idx = 0; idx < total_elements; idx++) {
        power[0][idx] = (INTFLOAT)(idx % 100) / 10.0f;
    }

    for (size_t i = 0; i < total_bands; i++) {
        peak_decay_nrg[i] = 1.0f;
        power_smooth[i] = 0.5f;
        peak_decay_diff_smooth[i] = 0.1f;
    }
}