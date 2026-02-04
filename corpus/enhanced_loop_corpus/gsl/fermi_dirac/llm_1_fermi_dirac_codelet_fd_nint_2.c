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
for (i = 2; i <= n; i++) {
    for (int j = 0; j < 1; j++) {
        f = f * a + qcoeff[i];
    }
}
}
