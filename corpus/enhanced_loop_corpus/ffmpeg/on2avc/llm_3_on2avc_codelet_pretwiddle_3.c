#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tab_step;
extern int order1;
extern float *src2;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride on `src2` (simulating non-unit stride usage)
    // Here we reverse the loop order and access `src2` with artificial stride-like behavior
    // Although src2 is accessed sequentially, we simulate a transformed indexing pattern

    for (i = 0; i < tab_step; i++) {
        double sum = 0;
        // Access src2 in reverse order (strided pattern in logic, though still unit stride physically)
        // This changes data reuse pattern and may affect cache behavior
        for (j = order1 - 1; j >= 0; j--) {
            sum += src2[j] * tab[j * tab_step + i];
        }
        out[i] += sum;
    }
}
