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
    int temp_max = max_slen2;
    for (int i = 11; i < 21; i++) {
        if (scalefac->l[i] > temp_max)
            temp_max = scalefac->l[i];
    }
    max_slen2 = temp_max;
}
