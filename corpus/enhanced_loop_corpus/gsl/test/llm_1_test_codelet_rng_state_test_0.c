#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long test_a[10000];
extern unsigned long test_b[10000];
extern int i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 100; ++i) {
    int base = i * 100;
    for (int k = 0; k < 100; ++k) {
        int idx = base + k;
        status |= (test_b[idx] != test_a[idx]);
    }
}
}
