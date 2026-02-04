#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < n; i++) {
        temp = (n + 1 - i);
        r[i] = temp;
    }
}
