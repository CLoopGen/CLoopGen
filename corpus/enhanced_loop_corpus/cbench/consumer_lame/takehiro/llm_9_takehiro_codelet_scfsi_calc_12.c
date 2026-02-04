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
for (sfb = 0; sfb < 11; sfb += 2) {
    int temp1 = scalefac[1][ch].l[sfb];
    int temp2 = (sfb + 1 < 11) ? scalefac[1][ch].l[sfb + 1] : temp1;
    if (temp1 >= 0) {
        c1++;
        if (s1 < temp1)
            s1 = temp1;
    }
    if (temp2 >= 0 && sfb + 1 < 11) {
        c1++;
        if (s1 < temp2)
            s1 = temp2;
    }
}
}
