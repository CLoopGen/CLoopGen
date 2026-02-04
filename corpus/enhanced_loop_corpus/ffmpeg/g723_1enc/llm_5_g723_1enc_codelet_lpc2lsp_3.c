#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 12; i++) {
        int val = f[i];
        int neg_val = -val;
        int use_neg = val < 0;
        int abs_val = use_neg ? neg_val : val;
        max = max > abs_val ? max : abs_val;
    }
}
