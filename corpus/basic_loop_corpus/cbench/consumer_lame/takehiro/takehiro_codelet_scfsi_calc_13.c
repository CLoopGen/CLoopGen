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
for (; sfb < 21; sfb++) {
    if (scalefac[1][ch].l[sfb] < 0)
        continue;
    c2++;
    if (s2 < scalefac[1][ch].l[sfb])
        s2 = scalefac[1][ch].l[sfb];
}

}
