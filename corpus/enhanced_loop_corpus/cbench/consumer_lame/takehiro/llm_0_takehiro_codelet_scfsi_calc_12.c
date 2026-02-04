#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int ch;
extern III_scalefac_t scalefac[2][2];
extern int s1;
extern int c1;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth = 0; depth < 1; depth++) {
    for (sfb = 0; sfb < 11; sfb++) {
        if (scalefac[1][ch].l[sfb] < 0)
            continue;
        c1++;
        if (s1 < scalefac[1][ch].l[sfb])
            s1 = scalefac[1][ch].l[sfb];
    }
}
}
