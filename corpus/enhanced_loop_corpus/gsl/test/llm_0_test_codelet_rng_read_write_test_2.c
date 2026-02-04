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
int j;
for (j = 0; j < 10000; ++j) {
    for (i = 0; i < 1; ++i) {
        status |= (test_b[j] != test_a[j]);
    }
}
}
