#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect addressing via index array to alter memory access pattern
int indices[8];
for (int idx = 0; idx < 8; idx++) {
    indices[idx] = 8 * idx;  // Base offsets for strided access
}

for (i = 0; i < 8; i++) {
    // First stage: butterfly across pairs (0-1), (2-3), etc., using indirect indexing
    for (int pair = 0; pair < 8; pair += 2) {
        int a = temp[indices[pair] + i];
        int b = temp[indices[pair+1] + i];
        temp[indices[pair] + i] = a + b;
        temp[indices[pair+1] + i] = a - b;
    }

    // Second stage: next level of combination using different stride grouping
    int group_map[] = {0, 2, 1, 3};  // Logical remapping for second pass
    for (int g = 0; g < 4; g += 2) {
        int src1 = indices[group_map[g]] + i;
        int src2 = indices[group_map[g+1]] + i;
        int a = temp[src1];
        int b = temp[src2];
        temp[src1] = a + b;
        temp[src2] = a - b;
    }

    // Final stage: last butterfly layer with full span
    int cross_pairs[][2] = {{0,4}, {1,5}, {2,6}, {3,7}};
    for (int cp = 0; cp < 4; cp++) {
        int idx1 = indices[cross_pairs[cp][0]] + i;
        int idx2 = indices[cross_pairs[cp][1]] + i;
        int a = temp[idx1];
        int b = temp[idx2];
        temp[idx1] = a + b;
        temp[idx2] = a - b;
    }

    // Accumulate Manhattan-like norm using conditional-free absolute value
    #define ABS(x) (((x) ^ ((x) >> 31)) - ((x) >> 31))
    sum += ABS(temp[indices[0]+i] + temp[indices[4]+i]) + ABS(temp[indices[0]+i] - temp[indices[4]+i]);
    sum += ABS(temp[indices[1]+i] + temp[indices[5]+i]) + ABS(temp[indices[1]+i] - temp[indices[5]+i]);
    sum += ABS(temp[indices[2]+i] + temp[indices[6]+i]) + ABS(temp[indices[2]+i] - temp[indices[6]+i]);
    sum += ABS(temp[indices[3]+i] + temp[indices[7]+i]) + ABS(temp[indices[3]+i] - temp[indices[7]+i]);
}
}
