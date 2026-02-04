#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in_layout;
extern uint64_t out_layout;
extern int i;
extern double matrix[64][64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[64] = {0.0};
    for (i = 0; i < 64; i++) {
        if (in_layout & out_layout & (1ULL << i)) {
            temp[i] = 1.;
            matrix[i][i] = temp[i]; // Introduce temporary variable: creates WAR/WAW dependency within iteration, breaks direct write-to-matrix without intermediate
        }
    }
}
