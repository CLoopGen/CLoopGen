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
    int start = (i0 >> 2);
    int end = (i1 >> 2);
    for (i = start; i < end; i++) {
        int idx = 4 * i;
        long long temp1 = (long long)p[idx - 2] + p[idx + 2];
        long long temp2 = (long long)p[idx - 1] + p[idx + 1];
        p[idx] += (29066LL * temp1 + 32768LL) >> 16;
        if (idx + 2 < (i1 >> 1) * 2) {
            p[idx + 2] += (29066LL * temp2 + 32768LL) >> 16;
        }
    }
}
