#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_gain_val_tab[256][3];
extern const uint8_t ff_gain_exp_tab[256];
extern int n;
extern int skip_first;
extern int *m;
extern int i;
extern int v[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = !skip_first;
    for (i = start; i < 3; i += 1) {
        int val = ff_gain_val_tab[n][i] * (unsigned int)m[i];
        v[i] = (val >> ff_gain_exp_tab[n]) + (val >> (ff_gain_exp_tab[n] + 2));
    }
}
