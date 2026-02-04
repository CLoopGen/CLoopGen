#include <stdio.h>

#include <inttypes.h>

extern int x;
extern char Z[26];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    x = 0;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 2; j++) {
            Z[x++] = 0;
        }
    }
}
