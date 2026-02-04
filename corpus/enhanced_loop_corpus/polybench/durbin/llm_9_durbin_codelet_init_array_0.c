#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double r[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n * n; i++) {
        int idx = i % n;
        r[idx] += (double)(n + 1 - idx) / (i / n + 1);
    }
}
