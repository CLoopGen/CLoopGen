#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double y[2100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        y[i] = 0;
        if (i + 1 < n) {
            y[i + 1] = 0;
        }
    }
}
