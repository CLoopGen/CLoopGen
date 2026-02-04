#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_tests; i++) {
        if (i % 2 == 0) {
            permute[i] = i;
        } else {
            permute[i] = i + 1;
        }
    }
}
