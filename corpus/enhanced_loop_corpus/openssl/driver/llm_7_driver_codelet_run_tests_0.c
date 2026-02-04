#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < num_tests; i++)
        permute[i] = permute[i-1] + 1;
    if (num_tests > 0)
        permute[0] = 0;
}
