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
    if (n < 2) return;
    for (i = 2; i <= n; i++) {
        if (a > 0.0) {
            f = f * a + qcoeff[i];
        }
    }
}
