#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *window;
extern int i;
extern int n;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (i = 0; i < n2; i += stride) {
        float temp = window[i];
        window[n - 1 - i] = temp;
        window[i] = temp * 1.5f;
        stride = 1 + ((i + 1) & 1); // Alternates between step 1 and 2, increasing computational variation
    }
}
