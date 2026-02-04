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
    for (i = 0; i < (sizeof (matrix) / sizeof ((matrix)[0])); i += 2) {
        if (in_ch_layout & out_ch_layout & (1ULL << i)) {
            matrix[i][i] = 1.;
            if (i + 1 < (sizeof (matrix) / sizeof ((matrix)[0]))) {
                matrix[i + 1][i + 1] = 1.;
            }
        }
    }
}
