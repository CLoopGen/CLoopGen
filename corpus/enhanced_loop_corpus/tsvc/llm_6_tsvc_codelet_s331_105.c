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
    for (int i = 0; i < 32000; i++) {
        int cond = (a[i] < (real_t)0.);
        if (cond) {
            local_j = i;
        }
    }
    chksum = (real_t)local_j;
}
}
