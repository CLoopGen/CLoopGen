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
for (; sfb < 21; sfb += 2) {
    int val1 = scalefac[1][ch].l[sfb];
    if (val1 >= 0) {
        c2++;
        if (s2 < val1)
            s2 = val1;
    }
    if (sfb + 1 < 21) {
        int val2 = scalefac[1][ch].l[sfb + 1];
        if (val2 >= 0) {
            c2++;
            if (s2 < val2)
                s2 = val2;
        }
    }
}
}
