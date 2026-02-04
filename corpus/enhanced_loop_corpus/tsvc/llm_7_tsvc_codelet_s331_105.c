#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern int j;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    int local_j = -1;
    for (int i = 31999; i >= 0; i--) {
        if (a[i] < (real_t)0.) {
            local_j = i;
            break;
        }
    }
    chksum = (real_t)local_j;
}
}
