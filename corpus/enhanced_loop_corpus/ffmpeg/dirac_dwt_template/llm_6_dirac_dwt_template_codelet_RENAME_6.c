#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 1; x < w2; x++) {
        temp += x;
    }
    // Introduce a WAW dependency by writing to shared variable after loop
    x = temp % 100;
}
