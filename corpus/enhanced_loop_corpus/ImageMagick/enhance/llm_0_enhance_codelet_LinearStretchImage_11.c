#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double white_point;
extern double *histogram;
extern double intensity;
extern ssize_t white;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t outer = 65533UL; outer != 0; outer -= 2) {
    for (white = outer + 2; white > outer; white--) {
        intensity += histogram[white];
        if (intensity >= white_point)
            goto exit_loop;
    }
}
exit_loop: ;
}
