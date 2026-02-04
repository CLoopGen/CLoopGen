#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[26];
    int i;
    // Eliminate loop-carried dependency by using temporary storage first (no RAW across iterations)
    for (i = 0; i < 26; i++) {
        temp[i] = 0;
    }
    for (i = 0; i < 26; i++) {
        Z[i] = temp[i]; // Decoupled write to Z, no data dependency between iterations
    }
    x = 26;
}
