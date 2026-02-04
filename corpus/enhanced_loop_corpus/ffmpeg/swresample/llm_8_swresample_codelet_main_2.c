#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < max_tests; i++) {
    remaining_tests[i] = i * i + 2*i - 1;
    for (j = 0; j < 5; j++) {
        remaining_tests[i] += j;
    }
}
}
