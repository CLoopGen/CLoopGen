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
    // Increase loop depth significantly by splitting the iteration space into blocks
    const int block_size = 64;
    const int num_blocks = (428 + block_size - 1) / block_size;
    
    for (int b = 0; b < num_blocks; b++) {
        int start = b * block_size;
        int end = (start + block_size > 428) ? 428 : start + block_size;
        
        for (i = start; i < end; i++) {
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
}
