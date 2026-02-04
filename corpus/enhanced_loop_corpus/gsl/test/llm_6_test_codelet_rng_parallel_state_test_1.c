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
    int local_status = 0;
    for (i = 0; i < 10000; ++i) {
        local_status |= (test_b[i] != test_a[i]);
        local_status |= (test_c[i] != test_d[i]);
        local_status |= (test_e[i] != test_f[i]);
    }
    status |= local_status;
}
