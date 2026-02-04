#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern int i;
extern int k;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k <= n; k++) {
    qcoeff[k] = -qcoeff[k - 1];
    if (k >= 3) {
        for (i = k - 1; i >= 2; i--) {
            qcoeff[i] = i * qcoeff[i] - (k - (i - 1)) * qcoeff[i - 1];
        }
    }
}
}
