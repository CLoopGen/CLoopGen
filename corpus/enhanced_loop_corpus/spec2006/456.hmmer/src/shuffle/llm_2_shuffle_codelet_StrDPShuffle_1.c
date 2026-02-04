#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 26; x += 2) {
        Z[x] = 0;
        if (x + 1 < 26) {
            Z[x + 1] = 0;
        }
    }
}
