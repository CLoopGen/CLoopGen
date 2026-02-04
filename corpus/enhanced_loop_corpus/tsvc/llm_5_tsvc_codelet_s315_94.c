#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern real_t x;
extern real_t chksum;
extern int _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    x = a[0];
    index = 0;
    int found_better = 1;
    for (int i = 1; i < 32000; ++i) {
        found_better = (a[i] > x);
        if (found_better) {
            x = a[i];
            index = i;
        }
    }
    chksum = x + (real_t)index;
}
}
