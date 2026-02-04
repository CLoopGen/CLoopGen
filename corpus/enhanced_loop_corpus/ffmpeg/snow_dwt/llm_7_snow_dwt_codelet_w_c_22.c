#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int type;
extern int s;
extern int i;
extern int j;
extern  int dec_count;
extern int tmp[1024];
extern int level;
extern int ori;
extern  int scale[2][2][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0; // Eliminate WAW hazard on 's' by using a private accumulator
    for (level = 0; level < dec_count; level++) {
        for (ori = level ? 1 : 0; ori < 4; ori++) {
            int size = w >> (dec_count - level);
            int sx = (ori & 1) ? size : 0;
            int stride = 32 << (dec_count - level);
            int sy = (ori & 2) ? stride >> 1 : 0;
            int scale_val = scale[type][dec_count - 3][level][ori];
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    int index = sx + sy + i * stride + j;
                    int fetched = tmp[index]; // RAW: tmp use after definition in memory
                    int scaled = fetched * scale_val;
                    int abs_val = (scaled >= 0) ? scaled : -scaled;
                    temp_sum += abs_val; // Accumulate into local variable to break loop-carried dependency on global 's'
                }
            }
        }
    }
    s += temp_sum; // Update global 's' once after loop
}
