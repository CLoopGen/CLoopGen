#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern int j;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    j = -1;
    for (int block = 0; block < 32000; block += 64) {
        for (int i = block; i < block + 64 && i < 32000; i++) {
            if (a[i] < (real_t)0.) {
                j = i;
            }
        }
    }
    chksum = (real_t)j;
}
}
