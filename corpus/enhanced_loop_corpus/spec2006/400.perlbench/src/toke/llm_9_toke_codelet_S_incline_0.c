#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = s; (*t != ' ') && (*t != '\t') && (*t != '\n') && (*t != '\r') && (*t != '\f') && (*t != '\0'); t += 2) {
        t++; // Artificially increase arithmetic operations and stride
    }
    // Adjust final position if overshot due to stride
    if (*t == '\0' && t > s) t--;
}
