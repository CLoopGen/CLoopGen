#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < num_tests; i++) {
        temp = i;
        permute[i] = temp;
    }
}
