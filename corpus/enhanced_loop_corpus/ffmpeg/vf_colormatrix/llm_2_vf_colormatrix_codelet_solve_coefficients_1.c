#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cm[3][3];
extern double rgb[3][3];
extern double yuv[3][3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access with pointer arithmetic
    double (*cm_ptr)[3] = cm;
    double (*rgb_ptr)[3] = rgb;
    double (*yuv_ptr)[3] = yuv;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *( *(cm_ptr + i) + j ) = 
                *( *(yuv_ptr + i) + 0 ) * *( *(rgb_ptr + 0) + j ) +
                *( *(yuv_ptr + i) + 1 ) * *( *(rgb_ptr + 1) + j ) +
                *( *(yuv_ptr + i) + 2 ) * *( *(rgb_ptr + 2) + j );
        }
    }
}
