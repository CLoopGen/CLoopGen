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
    int i;
    for (i = 11; i < 21; i++) {
        int local_sfb = i; // Eliminate loop-carried dependency on sfb by using local copy
        if (scalefac->l[local_sfb] < pretab[local_sfb]) {
            sfb = local_sfb;
            break;
        } else {
            sfb = 21; // Update sfb in every iteration, but no dependency on previous iteration
        }
    }
}
