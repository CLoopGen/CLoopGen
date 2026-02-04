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
    int skip_band = (peak_decay_factor <= 0.0f);
    if (skip_band) continue;
    for (n = n0; n < nL; n++) {
        float decayed_peak = peak_decay_factor * peak_decay_nrg[i];
        float diff = peak_decay_nrg[i] - power[i][n];
        float denom;

        // Introduce early skip based on energy difference
        if (diff < 1e-5f) {
            power_smooth[i] += a_smooth * (power[i][n] - power_smooth[i]);
            peak_decay_diff_smooth[i] = a_smooth * diff + (1.0f - a_smooth) * peak_decay_diff_smooth[i];
            transient_gain[i][n] = 1.F;
            continue;
        }

        peak_decay_nrg[i] = decayed_peak > power[i][n] ? decayed_peak : power[i][n];
        power_smooth[i] += a_smooth * (power[i][n] - power_smooth[i]);
        peak_decay_diff_smooth[i] += a_smooth * (peak_decay_nrg[i] - power[i][n] - peak_decay_diff_smooth[i]);
        denom = transient_impact * peak_decay_diff_smooth[i];
        transient_gain[i][n] = (denom > power_smooth[i] && denom > 1e-6f) ? (power_smooth[i] / denom) : 1.F;
    }
}
}
