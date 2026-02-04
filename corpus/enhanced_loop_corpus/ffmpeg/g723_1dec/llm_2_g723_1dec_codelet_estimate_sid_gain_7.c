#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int shift;
extern int seg;
extern int seg2;
extern int t;
extern int val;
extern int val_add;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *val_array = (int*)malloc(shift * sizeof(int));
    int *val_add_array = (int*)malloc(shift * sizeof(int));
    
    val_array[0] = val;
    val_add_array[0] = val_add;
    
    for (i = 0; i < shift; i++) {
        t = seg * 32 + (val_array[i] << seg2);
        t *= t;
        if (x >= t) {
            if (i + 1 < shift)
                val_array[i + 1] = val_array[i] + val_add_array[i];
        } else {
            if (i + 1 < shift)
                val_array[i + 1] = val_array[i] - val_add_array[i];
        }
        if (i + 1 < shift)
            val_add_array[i + 1] = val_add_array[i] >> 1;
    }
    
    val = val_array[shift - 1];
    val_add = val_add_array[shift - 1];
    
    free(val_array);
    free(val_add_array);
}
