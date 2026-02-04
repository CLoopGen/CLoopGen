#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop that runs only once to wrap the original logic, increasing nesting depth
    for (int outer = 0; outer < 1; outer++) {
        for (p = font; *p != '\x00'; p++) {
            if ((*p == ':') || (*p == ';') || (*p == ','))
                fonts++;
        }
    }
}
