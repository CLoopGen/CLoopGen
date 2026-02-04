#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 11; i += 2) {
        if (i + 1 <= 11) {
            V[i] = V[i - 1] * tau;
            V[i + 1] = V[i - 1] * tau * tau;
        } else {
            V[i] = V[i - 1] * tau;
        }
    }
}
