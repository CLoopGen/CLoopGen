#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int ch;
extern III_scalefac_t scalefac[2][2];
extern int s2;
extern int c2;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; sfb < 42; sfb += 2) {
    int idx = sfb / 2;
    if (scalefac[1][ch].l[idx] < 0)
        continue;
    c2++;
    if (s2 < scalefac[1][ch].l[idx])
        s2 = scalefac[1][ch].l[idx];
    if (idx + 1 < 22 && scalefac[1][ch].l[idx + 1] >= 0) {
        c2++;
        if (s2 < scalefac[1][ch].l[idx + 1])
            s2 = scalefac[1][ch].l[idx + 1];
    }
}
}
