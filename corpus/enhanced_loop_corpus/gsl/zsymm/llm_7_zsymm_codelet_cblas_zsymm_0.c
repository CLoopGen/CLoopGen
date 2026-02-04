#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n1; i++) {
        double temp_real = 0.0, temp_imag = 0.0;
        for (j = 0; j < n2; j++) {
            int idx = ldc * i + j;
            // Eliminate WAW and WAR hazards by using temporaries and updating only once per row
            // Introduce loop-carried dependence on temp values (though trivial here)
            temp_real = 0.0;
            temp_imag = 0.0;
            ((double *)C)[2 * idx] = temp_real;
            ((double *)C)[2 * idx + 1] = temp_imag;
        }
    }
}
