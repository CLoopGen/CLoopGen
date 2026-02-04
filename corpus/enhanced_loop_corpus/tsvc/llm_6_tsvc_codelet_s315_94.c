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
        real_t local_x = a[0];
        int local_index = 0;
        for (int i = 1; i < 32000; ++i) {
            real_t val = a[i];
            if (val > local_x) {
                local_x = val;
                local_index = i;
            }
        }
        x = local_x;
        index = local_index;
        chksum = x + (real_t)index;
    }
}
