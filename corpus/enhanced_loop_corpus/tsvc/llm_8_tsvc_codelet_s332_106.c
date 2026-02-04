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
for (int nl = 0; nl < 50000; nl++) {
    index = -2;
    value = -1.;
    for (int i = 0; i < 32000; i += 2) {
        if (a[i] > t && a[i+1] > t) {
            index = i + 1;
            value = a[i+1];
            goto L20;
        }
        else if (a[i] > t) {
            index = i;
            value = a[i];
            goto L20;
        }
    }
  L20:
    chksum = value * value + (real_t)(index * index);
}
}
