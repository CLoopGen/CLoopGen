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
    int outer_i;
    for (outer_i = !skip_first; outer_i < 3; outer_i++) {
        if (outer_i == i) {
            v[i] = (ff_gain_val_tab[n][i] * (unsigned int)m[i]) >> ff_gain_exp_tab[n];
            break;
        }
        i = outer_i;
        v[i] = (ff_gain_val_tab[n][i] * (unsigned int)m[i]) >> ff_gain_exp_tab[n];
    }
}
