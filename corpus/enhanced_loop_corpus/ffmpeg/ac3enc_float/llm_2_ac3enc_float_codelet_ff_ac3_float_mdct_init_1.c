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
    int stride = 2;
    for (i = 0; i < n2; i += stride) {
        if (i < n2 - 1) {
            window[n - 1 - i] = window[i];
            window[n - 1 - (i + 1)] = window[i + 1];
        } else if (i == n2 - 1) {
            window[n - 1 - i] = window[i];
        }
    }
}
