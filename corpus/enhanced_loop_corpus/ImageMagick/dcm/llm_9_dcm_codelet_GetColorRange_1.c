#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            p++;
            while (*p != ')' && *p != '\x00') {
                p++;
            }
            if (*p == '\x00')
                break;
        } else {
            p += 2; // Skip every other character, increasing stride to reduce trip count
            if (*p == '\x00' || *(p-1) == '-')
                break;
        }
    }
}
