#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // We traverse the string with a stride of 2, checking every second character
    // This changes the access pattern from sequential to strided
    for (p = kf; *p; p += 2) {
        if (*p == ',')
            n++;
        // Check the next character if exists (to simulate processing same elements as original)
        if (*(p + 1) && *(p + 1) == ',')
            n++;
    }
}
