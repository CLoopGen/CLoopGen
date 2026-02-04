#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v2;
extern int len;
extern int i;
extern unsigned int *v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        int prev_t = v1[0] - v2[0];
        v1[0] += v2[0];
        for (i = 1; i < len; i++) {
            int t = v1[i] - v2[i];
            v2[i-1] = prev_t;
            v1[i] += v2[i];
            prev_t = t;
        }
        v2[len-1] = prev_t;
    }
}
