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
for (i = 0; i < NR_PAR_BANDS[is34]; i += 2) {
    for (n = n0; n < nL; n++) {
        float decayed_peak_0 = peak_decay_factor * peak_decay_nrg[i];
        float decayed_peak_1 = (i+1 < NR_PAR_BANDS[is34]) ? peak_decay_factor * peak_decay_nrg[i+1] : 0.0f;
        float denom_0, denom_1;

        // Update peak decay energy for band i
        peak_decay_nrg[i] = (decayed_peak_0 > power[i][n]) ? decayed_peak_0 : power[i][n];
        
        // Unroll inner loop by processing two bands if available
        if (i+1 < NR_PAR_BANDS[is34]) {
            peak_decay_nrg[i+1] = (decayed_peak_1 > power[i+1][n]) ? decayed_peak_1 : power[i+1][n];
        }

        // Smooth power for band i
        power_smooth[i] += a_smooth * (power[i][n] - power_smooth[i]);
        if (i+1 < NR_PAR_BANDS[is34]) {
            power_smooth[i+1] += a_smooth * (power[i+1][n] - power_smooth[i+1]);
        }

        // Smooth peak decay difference for band i
        peak_decay_diff_smooth[i] += a_smooth * (peak_decay_nrg[i] - power[i][n] - peak_decay_diff_smooth[i]);
        if (i+1 < NR_PAR_BANDS[is34]) {
            peak_decay_diff_smooth[i+1] += a_smooth * (peak_decay_nrg[i+1] - power[i+1][n] - peak_decay_diff_smooth[i+1]);
        }

        // Compute transient gain for band i
        denom_0 = transient_impact * peak_decay_diff_smooth[i];
        transient_gain[i][n] = (denom_0 > power_smooth[i]) ? power_smooth[i] / denom_0 : 1.F;

        // Compute transient gain for band i+1 if valid
        if (i+1 < NR_PAR_BANDS[is34]) {
            denom_1 = transient_impact * peak_decay_diff_smooth[i+1];
            transient_gain[i+1][n] = (denom_1 > power_smooth[i+1]) ? power_smooth[i+1] / denom_1 : 1.F;
        }
    }
}
}
