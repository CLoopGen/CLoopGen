#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int remaining_tests[117600];
extern int max_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < max_tests; i++) {
        if (i < max_tests / 2) {
            remaining_tests[i] = i;
        } else {
            remaining_tests[i] = 0;
        }
    }
}
