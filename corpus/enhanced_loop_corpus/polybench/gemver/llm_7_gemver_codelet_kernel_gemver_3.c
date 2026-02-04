#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2000];
extern double z[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        x[0] = x[0] + z[0];
        for (i = 1; i < n; i++) {
            x[i] = x[i-1] + z[i];
        }
    }
}
