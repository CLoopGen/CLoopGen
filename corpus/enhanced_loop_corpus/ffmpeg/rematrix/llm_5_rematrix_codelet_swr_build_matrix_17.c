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
for (i = 0; i < (sizeof (matrix) / sizeof ((matrix)[0])); i++) {
    int64_t mask = 1ULL << i;
    if (!(in_ch_layout & mask) || !(out_ch_layout & mask)) continue;
    matrix[i][i] = 1.;
}
}
