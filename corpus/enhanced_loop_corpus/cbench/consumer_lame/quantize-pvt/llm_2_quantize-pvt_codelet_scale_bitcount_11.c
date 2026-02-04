#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int pretab[21];
extern III_scalefac_t *scalefac;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int temp_sfb = 11; temp_sfb < 21; temp_sfb += 2) {
    if (scalefac->l[temp_sfb] < pretab[temp_sfb])
        break;
}
}
