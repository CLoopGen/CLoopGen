#include <stdio.h>

#include <inttypes.h>

extern int *spiral_search_x;
extern int *spiral_search_y;
extern int i;
extern int k;
extern int l;
extern int search_range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k = 1;
    for (int l_val = 1; l_val <= (((1) > (search_range)) ? (1) : (search_range)); l_val++) {
        int segment_start = temp_k;
        for (int i = -l_val + 1; i < l_val; i++) {
            int idx1 = segment_start + 2 * (i + l_val - 1);
            spiral_search_x[idx1]     = i;
            spiral_search_y[idx1]     = -l_val;
            spiral_search_x[idx1 + 1] = i;
            spiral_search_y[idx1 + 1] = l_val;
        }
        segment_start += 4 * (l_val - 1);
        for (int i = -l_val; i <= l_val; i++) {
            int idx2 = segment_start + 2 * (i + l_val);
            spiral_search_x[idx2]     = -l_val;
            spiral_search_y[idx2]     = i;
            spiral_search_x[idx2 + 1] = l_val;
            spiral_search_y[idx2 + 1] = i;
        }
        temp_k += 4 * l_val;
    }
    k = temp_k;
}
