#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100000; nl++) {
        j = -1;
        int i = 0;
        for (; i < 32000; ) {
            if (a[i] > (real_t)0.) {
                j++;
                a[i] = b[j];
            }
            i++;
        }
    }
}
