#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (sfb = 11; sfb < 21; sfb++) {
        for (int inner = 0; inner < 1; inner++) {
            if (scalefac->l[sfb] > max_slen2)
                max_slen2 = scalefac->l[sfb];
        }
    }
}
