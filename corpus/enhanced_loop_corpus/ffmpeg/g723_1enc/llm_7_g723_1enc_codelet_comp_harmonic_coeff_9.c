#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max = max;
    for (i = 0; i < 15; i += 2) {
        int abs_val_i = energy[i] >= 0 ? energy[i] : -energy[i];
        local_max = local_max > abs_val_i ? local_max : abs_val_i;
        
        if (i + 1 < 15) {
            int abs_val_i1 = energy[i+1] >= 0 ? energy[i+1] : -energy[i+1];
            local_max = local_max > abs_val_i1 ? local_max : abs_val_i1;
        }
    }
    max = local_max;
}
