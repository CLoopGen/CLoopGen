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
for (int nl = 0; nl < 200000; nl += 2) {
    x = a[0];
    index = 0;
    // Unrolled inner loop with stride of 4 to reduce branch overhead and increase operation density
    int limit = 32000 - 3;
    for (int i = 0; i < limit; i += 4) {
        if (a[i] > x) {
            x = a[i];
            index = i;
        }
        if (a[i+1] > x) {
            x = a[i+1];
            index = i+1;
        }
        if (a[i+2] > x) {
            x = a[i+2];
            index = i+2;
        }
        if (a[i+3] > x) {
            x = a[i+3];
            index = i+3;
        }
    }
    // Handle remaining elements
    for (int i = limit; i < 32000; ++i) {
        if (a[i] > x) {
            x = a[i];
            index = i;
        }
    }
    chksum = x + (real_t)index;
}

}
