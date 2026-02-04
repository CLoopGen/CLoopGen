#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double y[2100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < n; j += 2) {
        if (j + 1 < n) {
            y[j] = 0;
            y[j+1] = 0;
        } else {
            y[j] = 0;
        }
    }
}
