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
    int prev = 0;
    for (sfb = 11; sfb < 21; sfb++) {
        int current = scalefac->l[sfb] - pretab[sfb] + prev;
        scalefac->l[sfb] = current;
        prev = current;
    }
}
