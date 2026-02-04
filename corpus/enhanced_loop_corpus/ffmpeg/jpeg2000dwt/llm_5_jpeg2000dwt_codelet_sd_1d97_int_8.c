#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int threshold = 100;
    for (i = (i0 >> 1) - 2; i < (i1 >> 1) + 1; i++) {
        int sum = p[2 * i] + p[2 * i + 2];
        if (abs(sum) > threshold) {
            long long temp = (103949LL * sum + (1 << 15)) >> 16;
            p[2 * i + 1] -= temp;
        } else {
            continue;
        }
    }
}
