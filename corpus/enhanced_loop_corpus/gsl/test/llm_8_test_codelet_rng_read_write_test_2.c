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
for (i = 0; i < 5000; ++i) {
    for (j = 0; j < 2; ++j) {
        int idx = i * 2 + j;
        status |= (test_b[idx] != test_a[idx]);
    }
}
}
