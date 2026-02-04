#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < num_tests; i++) {
        permute[i] = 0;
        for (j = 0; j < 3; j++) {
            permute[i] += i * (j + 1);
        }
    }
}
