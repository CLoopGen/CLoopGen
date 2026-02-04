#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and reordered conditionals
    int *idx_ptr = libs1;
    Intersection *b_ptr = board;
    int *ml_ptr = ml;
    int local_libs[400]; // Local buffer to accumulate valid indices
    int temp_commonlibs = 0;
    int i;

    for (i = 0; i < liberties2; i++) {
        int index = *(idx_ptr + i); // Indirect access via offset
        // Reorder condition evaluation for potential short-circuit optimization
        if (b_ptr[index] != 0 || ml_ptr[index] == liberty_mark) {
            if (temp_commonlibs < maxlib)
                local_libs[temp_commonlibs] = index;
            temp_commonlibs++;
        }
    }

    // Copy results back to shared state
    for (i = 0; i < temp_commonlibs && i < maxlib; i++) {
        libs[i] = local_libs[i];
    }
    commonlibs = temp_commonlibs;
}
