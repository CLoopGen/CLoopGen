#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse order)
    for (i = 10; i >= 2; i -= 2) {
        V[i] = V[i - 2] * tau;
    }
    // Fill remaining elements with sequential dependency
    for (i = 1; i <= 11; i += 2) {
        if (i == 1) {
            V[i] = V[i - 1] * tau;
        } else if (i > 1) {
            V[i] = V[i - 1] * tau;
        }
    }
}
