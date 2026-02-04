#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            x[i] = 1 + (i / fn);
        } else {
            continue;
        }
    }
}
