#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 26; i++) {
        Z[i] = 0;
        x = i; // WAW dependency introduced: 'x' is written after previous write in loop iteration
    }
    x = 26; // Ensure x ends with expected magnitude
}
