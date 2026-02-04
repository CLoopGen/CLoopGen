#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (x = 0; x < 26; x++)
            Z[x] = 0;
    }
}
