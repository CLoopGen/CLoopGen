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
for (int nl = 0; nl < 200000; nl++) {
    index = -2;
    value = -1.;
    real_t temp_sum = 0.0;
    int match_count = 0;
    for (int i = 0; i < 32000; i++) {
        if (a[i] > t) {
            temp_sum += a[i];
            match_count++;
            if (match_count >= 3) {
                index = i;
                value = temp_sum / 3.0;
                goto L20;
            }
        }
    }
  L20:
    chksum = value + (real_t)index + (real_t)match_count;
}
}
