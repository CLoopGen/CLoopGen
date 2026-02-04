#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int tab_step;
extern int order0;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Traversal
    // Change access pattern to reverse and strided to simulate different cache behavior
    for (i = 0; i < tab_step; i++) {
        double sum = 0;
        // Traverse src and tab in reverse order (strided backwards)
        for (j = order0 - 1; j >= 0; j--) {
            sum += src[j] * tab[j * tab_step + i];  // Strided access remains, but direction changed
        }
        out[i] += sum;
    }
}
