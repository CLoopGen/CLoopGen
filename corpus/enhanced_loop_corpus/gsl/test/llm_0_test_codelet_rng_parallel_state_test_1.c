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
    for (int j = 0; j < 100; ++j) {
        for (i = j * 100; i < (j + 1) * 100 && i < 10000; ++i) {
            status |= (test_b[i] != test_a[i]);
            status |= (test_c[i] != test_d[i]);
            status |= (test_e[i] != test_f[i]);
        }
    }
}
