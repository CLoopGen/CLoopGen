#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern double **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate apparent data dependencies and unroll the loop partially to expose parallelism
    // No loop-carried dependencies; all iterations are independent
    // Using pointer arithmetic without chaining across iterations
    for (r = 1; r < rows; r += 2) {
        mx[r] = mx[0] + r * cols;
        if (r + 1 < rows) {
            mx[r + 1] = mx[0] + (r + 1) * cols;
        }
    }
}
