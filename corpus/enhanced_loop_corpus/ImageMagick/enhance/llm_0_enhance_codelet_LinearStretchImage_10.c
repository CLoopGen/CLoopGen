#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double black_point;
extern double *histogram;
extern double intensity;
extern ssize_t black;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < 1; outer++) {
        for (black = 0; black < (ssize_t)65535UL; black++) {
            intensity += histogram[black];
            if (intensity >= black_point)
                goto exit_loop;
        }
        exit_loop:;
    }
}
