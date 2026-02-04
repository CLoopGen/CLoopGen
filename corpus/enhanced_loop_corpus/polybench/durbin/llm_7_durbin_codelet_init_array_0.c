#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n; i++) {
        r[n - i] = i;
    }
}
