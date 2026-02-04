#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int i;
extern int sfb;
extern int max_slen1;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
max_slen1 = -1;
max_slen2 = -1;
for (i = 0; i < 6; i += 2) {
    for (sfb = 0; sfb < 6; sfb++) {
        int val1 = scalefac->s[sfb][i % 3];
        int val2 = (i + 1 < 3) ? scalefac->s[sfb][(i + 1) % 3] : val1;
        if (val1 > max_slen1) max_slen1 = val1;
        if (val2 > max_slen1) max_slen1 = val2;
    }
    for (sfb = 6; sfb < 12; sfb++) {
        int val1 = scalefac->s[sfb][i % 3];
        int val2 = (i + 1 < 3) ? scalefac->s[sfb][(i + 1) % 3] : val1;
        if (val1 > max_slen2) max_slen2 = val1;
        if (val2 > max_slen2) max_slen2 = val2;
    }
}
}
