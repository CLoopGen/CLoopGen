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
int indices[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
for (sfb = 0; sfb < 11; sfb++) {
    int idx = indices[sfb];
    if (scalefac[1][ch].l[idx] < 0)
        continue;
    c1++;
    if (s1 < scalefac[1][ch].l[idx])
        s1 = scalefac[1][ch].l[idx];
}
}
