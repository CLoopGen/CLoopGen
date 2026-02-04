#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 0; i <= (64 + 1) * (64 + 2); i += 64 + 2) {
    for (k = 0; k <= 64 + 1; k++) {
        int idx_i = i / (64 + 2);
        int idx_k = k;
        if (idx_i <= 64 + 1) {
            phi1[idx_i][idx_k] = 0.;
            phi2[idx_i][idx_k] = 0.;
        }
    }
}
}
