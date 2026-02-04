#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_tests && i < 1024; i += 2) {
        permute[i] = i;
        if (i + 1 < num_tests && i + 1 < 1024) {
            permute[i + 1] = i + 1;
        }
    }
}
