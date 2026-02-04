#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    float temp[14];
    for (j = 0; j < 14; j++) {
        temp[j] = diff_isf[j];
    }
    for (i = 1; i < 20 - 16; i++) {
        if (temp[i] + temp[i - 1] < 5.) {
            if (temp[i] > temp[i - 1]) {
                diff_isf[i - 1] = 5. - temp[i];
            } else {
                diff_isf[i] = 5. - temp[i - 1];
            }
        }
    }
}
