#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect and Strided Access using Offset Vector
    // Instead of direct neighbor checks, precompute offsets and use indirect indexing
    const int offsets[4] = {20, -1, -20, 1}; // N, W, S, E directions
    const int num_offsets = 4;

    // Cache invariant values
    Intersection board_val = board[str2];
    int string_num_val = string_number[str2];

    for (k = 0; k < liberties1; k++) {
        int lib_index = libs1[k];
        int matched = 0;

        // Use indirect addressing via offset array to create strided access pattern
        for (int d = 0; d < num_offsets && !matched; d++) {
            int pos = lib_index + offsets[d];
            if ((board[pos] == board_val) && (string_number[pos] == string_num_val)) {
                matched = 1;
            }
        }

        if (matched)
            commonlibs++;
    }
}
