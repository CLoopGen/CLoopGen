#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern double a;
extern double f;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 1) {
    for (i = n - 1; i >= 1; i--) {
        for (int k = 0; k < 1; k++) {
            f = f * a + qcoeff[i];
        }
    }
}
}
