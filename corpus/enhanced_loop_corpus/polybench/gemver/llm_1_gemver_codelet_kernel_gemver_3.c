#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2000];
extern double z[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        x[i] = x[i] + z[i];
        if (i + 1 < n)
            x[i + 1] = x[i + 1] + z[i + 1];
    }
}
