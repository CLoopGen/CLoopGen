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
    for (i = 0; i < 10000; ++i) {
        unsigned long temp_b = test_b[i];
        unsigned long temp_a = test_a[i];
        unsigned long temp_c = test_c[i];
        unsigned long temp_d = test_d[i];
        double temp_e = test_e[i];
        double temp_f = test_f[i];

        status |= (temp_b != temp_a);
        status |= (temp_c != temp_d);
        status |= (temp_e != temp_f);
    }
}
