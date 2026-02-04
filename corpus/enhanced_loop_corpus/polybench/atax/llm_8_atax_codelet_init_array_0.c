#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        x[i] = 1.0 + (i / fn);
        if (i + 1 < n) {
            x[i + 1] = 1.0 + ((i + 1) / fn);
        }
    }
}
