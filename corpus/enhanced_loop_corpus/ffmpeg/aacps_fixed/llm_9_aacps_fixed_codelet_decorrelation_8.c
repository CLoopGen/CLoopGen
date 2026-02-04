#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern  int NR_PAR_BANDS[];
extern int is34;
extern INTFLOAT *peak_decay_nrg;
extern INTFLOAT *peak_decay_diff_smooth;
extern int i;
extern int n;
extern int n0;
extern int nL;
extern  INTFLOAT peak_decay_factor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < NR_PAR_BANDS[is34] * 2; i += 2) {
    int idx = i % NR_PAR_BANDS[is34];
    int decayed_peak_1, decayed_peak_2;
    decayed_peak_1 = (int)(((int64_t)peak_decay_factor * peak_decay_nrg[idx] + 1073741824) >> 31);
    if (i + 1 < NR_PAR_BANDS[is34]) {
        decayed_peak_2 = (int)(((int64_t)peak_decay_factor * peak_decay_nrg[idx + 1] + 1073741824) >> 31);
    }
    if (!peak_decay_diff_smooth[idx]) {
        peak_decay_nrg[idx] = (INTFLOAT)(decayed_peak_1 + 1);
    }
    if (i + 1 < NR_PAR_BANDS[is34] && !peak_decay_diff_smooth[idx + 1]) {
        peak_decay_nrg[idx + 1] = (INTFLOAT)(decayed_peak_2 + 1);
    }
}
}
