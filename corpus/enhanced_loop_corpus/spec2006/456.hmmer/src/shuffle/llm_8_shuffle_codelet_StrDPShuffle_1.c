#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 52; i += 2) {
        Z[i/2] = 0;
        x = i/2;
    }
}
