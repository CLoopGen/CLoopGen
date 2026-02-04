#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = max;
    for (i = 1; i < 10 + 2; i++) {
        int abs_val = f[i] >= 0 ? f[i] : -f[i];
        temp_max = temp_max > abs_val ? temp_max : abs_val;
    }
    max = temp_max;
}
