#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled comparison check
    // This variant processes two elements per iteration to reduce trip count by ~half while increasing per-iteration work
    for (m = s; m < strend - 1 && (*m != c || *(m + 1) != c); m += 2)
        ;
    // Handle remaining element if needed
    if (m == strend - 1 && *m != c)
        m++;
}
