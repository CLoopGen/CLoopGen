#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int permute[1024];
extern int num_tests;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[1024];
    for (i = 0; i < num_tests; i++) {
        indices[i] = i;
    }
    for (i = 0; i < num_tests; i++) {
        int idx = indices[i];
        permute[idx] = idx;
    }
}
