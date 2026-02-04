#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (num_tests > 0) {
    i = 0;
    for (int level = 0; level < 1; level++) {
        for (; i < num_tests; i++) {
            permute[i] = i;
        }
    }
}
}
