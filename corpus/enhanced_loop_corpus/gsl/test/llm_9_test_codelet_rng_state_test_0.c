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
    for (i = 0; i < 5000; ++i) {
        status |= (test_b[2*i] != test_a[2*i]) | (test_b[2*i+1] != test_a[2*i+1]);
    }
}
