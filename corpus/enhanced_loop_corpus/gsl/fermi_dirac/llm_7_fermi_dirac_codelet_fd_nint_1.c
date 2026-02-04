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
        double prev_val = qcoeff[k - 1];
        qcoeff[k] = -prev_val;
        for (i = 2; i < k; i++) {
            int j = k - i + 1;
            qcoeff[j] = j * qcoeff[j] - (k - j + 1) * qcoeff[j - 1];
        }
    }
}
