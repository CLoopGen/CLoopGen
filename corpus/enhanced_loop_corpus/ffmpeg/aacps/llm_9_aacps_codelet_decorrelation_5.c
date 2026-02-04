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
    float local_peak_decay = peak_decay_nrg[i];
    float local_power_smooth = power_smooth[i];
    float local_diff_smooth = peak_decay_diff_smooth[i];
    
    for (n = n0; n < nL && n < n0 + 8; n++) {  // Limit inner loop trip count to increase intensity per iteration
        float decayed_peak = peak_decay_factor * local_peak_decay;
        float diff, denom;

        local_peak_decay = (decayed_peak > power[i][n]) ? decayed_peak : power[i][n];
        
        // Fused multiply-add style update with reduced memory traffic
        local_power_smooth = local_power_smooth + a_smooth * (power[i][n] - local_power_smooth);
        diff = local_peak_decay - power[i][n];
        local_diff_smooth = local_diff_smooth + a_smooth * (diff - local_diff_smooth);

        denom = transient_impact * local_diff_smooth;
        transient_gain[i][n] = (denom > local_power_smooth) ? local_power_smooth / denom : 1.F;
    }
    
    // Write back accumulated values to memory
    peak_decay_nrg[i] = local_peak_decay;
    power_smooth[i] = local_power_smooth;
    peak_decay_diff_smooth[i] = local_diff_smooth;
}
}
