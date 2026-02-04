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
for (int j = 0; j < 1; j++) {
    for (i = 0; i < (sizeof (matrix) / sizeof ((matrix)[0])); i++) {
        if (in_ch_layout & out_ch_layout & (1ULL << i))
            matrix[i][i] = 1.;
    }
}
}
