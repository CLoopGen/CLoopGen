#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = font; *p != '\x00'; p++) {
        if ((*p == ':') || (*p == ';') || (*p == ',')) {
            fonts++;
        }
        // Introduce an inner loop that does nothing but iterate once, increasing nesting depth
        for (int dummy = 0; dummy < 1; dummy++) {
            continue;
        }
    }
}
