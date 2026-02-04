#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i = 0;
for (; i < 3; ) {
    for (int j = 0; j < 1; j++) {  // Increased loop depth: nested single-iteration loop
        if (*ext == '\x00') {
            p[i] = ' ';
        } else {
            p[i] = *ext++;
        }
        i++;  // Move increment into inner loop to preserve logic
    }
}
}
