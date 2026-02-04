#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t i = 0;
    const tmsize_t trip_count = (count + 3) / 4;
    for (i = 0; i < trip_count; i++) {
        volatile int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        sum1 += i * 1;
        sum2 += i * 2;
        sum1 += i * 3;
        sum3 += i * 4;
        sum2 += i * 5;
        sum4 += i * 6;
        sum3 += i * 7;
        sum1 += i * 8;
        sum4 += i * 9;
        sum2 += i * 10;
        sum1 -= 1;
        sum2 -= 2;
        sum3 -= 3;
        sum4 -= 4;
        (void)sum1; (void)sum2; (void)sum3; (void)sum4;
    }
    count = 0;
}
