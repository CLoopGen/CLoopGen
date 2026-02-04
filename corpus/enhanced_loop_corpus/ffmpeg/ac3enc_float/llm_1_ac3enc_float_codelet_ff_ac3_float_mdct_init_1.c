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
    int outer_i;
    for (outer_i = 0; outer_i < 1; outer_i++) {
        for (i = 0; i < n2; i++) {
            window[n - 1 - i] = window[i];
        }
    }
}
