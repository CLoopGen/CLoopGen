#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 4;
for (i = 0; i < size; i++) {
    int val = r[i];
    max_r = (val > max_r) ? val : max_r;
    min_r = (val < min_r) ? val : min_r;
    
    // Unroll effect simulation with redundant comparisons (increased operations)
    if (i + 1 < size) {
        int val2 = r[i];
        max_r = (val2 >= max_r) ? val2 : max_r;
        min_r = (val2 <= min_r) ? val2 : min_r;
    }
}
}
