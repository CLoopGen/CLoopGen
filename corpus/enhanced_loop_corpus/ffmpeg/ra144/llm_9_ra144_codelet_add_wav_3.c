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
    for (i = !skip_first; i < 6; i++) {
        int idx = i % 3;
        long long scaled_val = ((long long)ff_gain_val_tab[n][idx] * (unsigned int)m[idx]) >> ff_gain_exp_tab[n];
        v[idx] = (int)(scaled_val + (i / 3)); 
    }
}
