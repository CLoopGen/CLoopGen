#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); p += 2) { // Increase stride to reduce trip count
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); ) {
                p++; // Single increment, but combined with outer loop stride of 2
                if ((*p == ')') || (*p == '\x00'))
                    break;
            }
            if (*p == '\x00')
                break;
        }
        // Skip every other character to reduce total iterations
        if (*(p + 1) == '\x00') break;
    }
}
