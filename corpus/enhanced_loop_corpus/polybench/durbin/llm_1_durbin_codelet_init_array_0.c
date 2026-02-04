#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        for (int k = 0; k < 1; k++) {
            r[i] = (n + 1 - i);
        }
    }
}
