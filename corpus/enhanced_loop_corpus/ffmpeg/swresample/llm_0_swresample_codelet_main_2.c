#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < max_tests; j++) {
        for (i = 0; i < 1; i++) {
            remaining_tests[j] = j;
        }
    }
}
