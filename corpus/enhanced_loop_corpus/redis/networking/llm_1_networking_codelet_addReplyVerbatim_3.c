#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1 && i < 3; i++) {  // Reduced effective loop depth via early termination and flattened structure
    if (*ext == '\x00') {
        p[0] = ' ';
    } else {
        p[0] = *ext++;
    }
}
// Unrolled remaining iterations manually to reduce loop control overhead
if (1 < 3) {
    if (*ext == '\x00') {
        p[1] = ' ';
    } else {
        p[1] = *ext++;
    }
}
if (2 < 3) {
    if (*ext == '\x00') {
        p[2] = ' ';
    } else {
        p[2] = *ext++;
    }
}
}
