#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern  int NR_PAR_BANDS[];
extern int is34;
extern INTFLOAT (*power)[32];
extern INTFLOAT (*transient_gain)[32];
extern INTFLOAT *peak_decay_nrg;
extern INTFLOAT *power_smooth;
extern INTFLOAT *peak_decay_diff_smooth;
extern  float transient_impact;
extern  float a_smooth;
extern int i;
extern int n;
extern int n0;
extern int nL;
extern  INTFLOAT peak_decay_factor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant with strided memory access across bands: process every 2nd band first, then the others (simulating cache-friendly blocking)
int stride = 2;
for (int step = 0; step < stride; step++) {
    for (i = step; i < NR_PAR_BANDS[is34]; i += stride) {
        for (n = n0; n < nL; n++) {
            float decayed_peak = peak_decay_factor * peak_decay_nrg[i];
            float denom;
            // Access arrays using direct indexed loads; simulate non-unit stride benefit via loop structure
            float pwr = power[i][n];
            peak_decay_nrg[i] = ((decayed_peak) > pwr ? decayed_peak : pwr);
            power_smooth[i] += a_smooth * (pwr - power_smooth[i]);
            float pd_diff = peak_decay_nrg[i] - pwr;
            peak_decay_diff_smooth[i] += a_smooth * (pd_diff - peak_decay_diff_smooth[i]);
            denom = transient_impact * peak_decay_diff_smooth[i];
            transient_gain[i][n] = (denom > power_smooth[i]) ? power_smooth[i] / denom : 1.F;
        }
    }
}
}
