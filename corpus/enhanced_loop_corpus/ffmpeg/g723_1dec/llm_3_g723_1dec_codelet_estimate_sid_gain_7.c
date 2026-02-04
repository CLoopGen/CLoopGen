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
    int access_pattern[64];
    for (int j = 0; j < 64; j++) {
        access_pattern[j] = (j * 7) % 61; // Strided indirect index generation
    }

    int temp_val = val;
    int temp_val_add = val_add;

    for (i = 0; i < shift; i++) {
        int idx = access_pattern[i % 64]; // Indirect, strided memory access pattern
        t = seg * 32 + ((temp_val ^ idx) << seg2); // Use index to perturb computation
        t *= t;
        if (x >= t)
            temp_val += temp_val_add;
        else
            temp_val -= temp_val_add;
        temp_val_add >>= 1;
    }

    val = temp_val;
    val_add = temp_val_add;
}
