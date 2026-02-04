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
    int temp = 0;
    for (sfb = 11; sfb < 21; sfb++) {
        temp += scalefac->l[sfb]; // Introduce loop-carried dependency via temp (WAW and RAW)
        if (scalefac->l[sfb] < pretab[sfb]) {
            break;
        }
    }
    // Use temp to prevent compiler optimization from eliminating it
    if (temp == 0) {
        sfb = 0;
    }
}
