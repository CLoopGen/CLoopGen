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
    unsigned long temp_status = 0;
    for (i = 0; i < 10000; ++i) {
        temp_status |= (test_b[i] != test_a[i]);
    }
    status |= temp_status;
}
