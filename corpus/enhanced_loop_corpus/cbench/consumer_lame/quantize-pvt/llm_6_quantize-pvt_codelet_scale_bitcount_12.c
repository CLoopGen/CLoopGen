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
    int temp[10];
    for (int i = 11; i < 21; i++) {
        temp[i - 11] = pretab[i];
    }
    for (sfb = 11; sfb < 21; sfb++)
        scalefac->l[sfb] -= temp[sfb - 11];
}
