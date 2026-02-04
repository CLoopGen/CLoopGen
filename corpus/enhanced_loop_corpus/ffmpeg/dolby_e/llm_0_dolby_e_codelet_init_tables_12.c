#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 25; i++) {
            if (j == 0) {
                exponent_tab[i * 2] = 1.F / (1 << i);
            } else {
                exponent_tab[i * 2 + 1] = 0.70710678118654757 / (1 << i);
            }
        }
    }
}
