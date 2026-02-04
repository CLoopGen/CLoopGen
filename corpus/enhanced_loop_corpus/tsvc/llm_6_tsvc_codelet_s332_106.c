#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern int t;
extern int _usr_index;
extern real_t value;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    index = -2;
    value = -1.;
    int found = 0;
    for (int i = 0; i < 32000 && !found; i++) {
        if (a[i] > t) {
            index = i;
            value = a[i];
            found = 1;
        }
    }
    chksum = value + (real_t)index;
}
}
