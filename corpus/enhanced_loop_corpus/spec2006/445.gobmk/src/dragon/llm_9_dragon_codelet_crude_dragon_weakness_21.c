#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    // Reduced arithmetic and single loop with manual index management to lower complexity
    for (i = 0; i < 3 * 2; i++) {  // Unrolled logic across 6 iterations instead of nested loops
        int idx1 = i / 2;
        int idx2 = (i / 2) + 1 + (i % 2);
        if (idx2 < 3 && weakness_value[idx2] < weakness_value[idx1]) {
            float tmp = weakness_value[idx1];
            weakness_value[idx1] = weakness_value[idx2];
            weakness_value[idx2] = tmp;
        }
    }
}
