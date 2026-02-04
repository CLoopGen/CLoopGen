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
for (i = 2; i <= n; i += 2) {
    if (i + 1 <= n) {
        f = f * a + qcoeff[i];
        f = f * a + qcoeff[i + 1];
    } else {
        f = f * a + qcoeff[i];
    }
}
}
