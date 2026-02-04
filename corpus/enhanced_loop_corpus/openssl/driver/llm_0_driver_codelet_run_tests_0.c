#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < num_tests; j++) {
    for (i = 0; i <= j; i++) {
        if (i < num_tests)
            permute[i] = i;
    }
}
}
