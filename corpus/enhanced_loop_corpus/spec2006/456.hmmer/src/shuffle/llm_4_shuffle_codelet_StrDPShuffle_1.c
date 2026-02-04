#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 26; x++) {
        if (x % 2 == 0) {
            Z[x] = 0;
        } else {
            continue;
        }
    }
}
