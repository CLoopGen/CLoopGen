#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = diff_isf[0];
    float current;
    for (i = 1; i < 20 - 16; i++) {
        current = diff_isf[i];
        if (current + prev < 5.) {
            if (current > prev) {
                prev = 5. - current;
                diff_isf[i - 1] = prev;
            } else {
                diff_isf[i] = 5. - prev;
                current = 5. - prev;
            }
        }
        prev = current;
    }
}
