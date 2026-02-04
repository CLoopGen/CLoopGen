#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int16_t shift;
extern int16_t sig_scaled[192];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Accesses every second element in both residual and sig_scaled arrays
    int upper_bound = subframe_size + (143 + 8 + 1);
    for (i = 0; i < upper_bound; i += 2) {
        if (i < upper_bound) {
            sig_scaled[i] = (unsigned int)residual[i] << -shift;
        }
        if (i + 1 < upper_bound) {
            sig_scaled[i + 1] = (unsigned int)residual[i + 1] << -shift;
        }
    }
    // Handle odd-sized ranges by covering last element if needed
    if ((upper_bound % 2) == 1 && upper_bound > 0) {
        i = upper_bound - 1;
        sig_scaled[i] = (unsigned int)residual[i] << -shift;
    }
}
