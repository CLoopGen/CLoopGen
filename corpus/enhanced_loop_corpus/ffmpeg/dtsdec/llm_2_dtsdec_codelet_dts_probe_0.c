#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[64];
extern int sum;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), with wrap-around handling
    int n = sizeof(markers) / sizeof(markers[0]);
    for (i = 0; i < n; i += 2) {
        int idx = i % n;
        sum += markers[idx];
        if (markers[max] < markers[idx])
            max = idx;
    }
    // Handle odd-sized arrays by including last element if stride skips it
    if (n % 2 == 1) {
        int last = n - 1;
        sum += markers[last];
        if (markers[max] < markers[last])
            max = last;
    }
}
