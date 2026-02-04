#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *w;
extern  int n;
extern float vsum;
extern float wsum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            float abs_val_ni = (w[n + i]) >= 0 ? w[n + i] : -w[n + i];
            float abs_val_nip1 = (w[n + i + 1]) >= 0 ? w[n + i + 1] : -w[n + i + 1];
            float denom_i = 1.F + abs_val_ni;
            float denom_ip1 = 1.F + abs_val_nip1;
            vsum += w[i] * (w[n + i] / denom_i) + w[i + 1] * (w[n + i + 1] / denom_ip1);
            wsum += w[i] + w[i + 1];
        } else {
            float abs_val_ni = (w[n + i]) >= 0 ? w[n + i] : -w[n + i];
            float denom_i = 1.F + abs_val_ni;
            vsum += w[i] * (w[n + i] / denom_i);
            wsum += w[i];
        }
    }
}
