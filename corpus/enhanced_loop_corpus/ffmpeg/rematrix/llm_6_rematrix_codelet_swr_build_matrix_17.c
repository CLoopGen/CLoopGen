#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double matrix[18][18];
extern int64_t in_ch_layout;
extern int64_t out_ch_layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < (sizeof (matrix) / sizeof ((matrix)[0])); i++) {
        j = i; // Introduce temporary variable to modify data dependency
        if (in_ch_layout & out_ch_layout & (1ULL << j)) {
            matrix[j][j] = 1.;
            if (j > 0) {
                matrix[j][j] += matrix[j-1][j-1]; // Introduce RAW dependency: current iteration reads previous write
            }
        }
    }
}
