#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < max_tests; i += 2) {
        remaining_tests[i] = i;
        if (i + 1 < max_tests) {
            remaining_tests[i + 1] = i + 1;
        }
    }
}
