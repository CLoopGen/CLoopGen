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
for (i = 0; i < NR_PAR_BANDS[is34]; i++) {
    for (n = n0; n < nL; n++) {
        float decayed_peak = peak_decay_factor * peak_decay_nrg[i];
        float denom;
        // Change memory access pattern: use a pointer stride to traverse power and transient_gain in row-major consecutive order
        INTFLOAT *power_row = power[i];
        INTFLOAT *transient_row = transient_gain[i];
        INTFLOAT current_power = power_row[n];
        peak_decay_nrg[i] = (decayed_peak > current_power) ? decayed_peak : current_power;
        power_smooth[i] += a_smooth * (current_power - power_smooth[i]);
        float diff = peak_decay_nrg[i] - current_power;
        peak_decay_diff_smooth[i] += a_smooth * (diff - peak_decay_diff_smooth[i]);
        denom = transient_impact * peak_decay_diff_smooth[i];
        transient_row[n] = (denom > power_smooth[i]) ? power_smooth[i] / denom : 1.F;
    }
}
}
