#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_aac_pow2sf_tab[428];
extern float ff_aac_pow34sf_tab[428];
extern int i;
extern  float exp2_lut[];
extern float t1;
extern float t2;
extern int t1_inc_cur;
extern int t2_inc_cur;
extern int t1_inc_prev;
extern int t2_inc_prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed direction and stride of 4
    // This changes the access pattern to non-sequential indices, simulating strided traversal
    // Initialize state variables appropriately for reverse traversal
    float temp_t1 = t1;
    float temp_t2 = t2;
    int temp_t1_inc_prev = t1_inc_prev;
    int temp_t2_inc_prev = t2_inc_prev;

    // We'll traverse backwards with a stride of 4 starting from last possible aligned index
    // Fill array in strided manner: ..., i-4, i-8, etc.
    // Use temporary storage to avoid dependency issues during reverse-stride update

    int indices[428];
    int count = 0;
    for (i = 427; i >= 0; i--) {
        indices[count++] = i;
    }

    // Reset tracking variables
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    t1 = temp_t1;
    t2 = temp_t2;

    for (int j = 0; j < 428; j++) {
        i = indices[j];  // Access index in reversed order
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;

        if (t1_inc_cur < t1_inc_prev)
            t1 *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2 *= 2;

        ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
