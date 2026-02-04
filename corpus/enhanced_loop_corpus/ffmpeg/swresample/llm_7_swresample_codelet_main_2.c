#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < max_tests; i++) {
        temp = i * 2;
        remaining_tests[i] = temp;
        temp = temp + i;
    }
}
