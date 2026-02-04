#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long test_a[10000];
extern unsigned long test_b[10000];
extern unsigned long test_c[10000];
extern unsigned long test_d[10000];
extern double test_e[10000];
extern double test_f[10000];
extern int i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 10000; i += 2) {
        status |= (test_b[i] != test_a[i]);
        status |= (test_c[i] != test_d[i]);
        status |= (test_e[i] != test_f[i]);
        
        if (i + 1 < 10000) {
            status |= (test_b[i+1] != test_a[i+1]);
            status |= (test_c[i+1] != test_d[i+1]);
            status |= (test_e[i+1] != test_f[i+1]);
        }
    }
}
