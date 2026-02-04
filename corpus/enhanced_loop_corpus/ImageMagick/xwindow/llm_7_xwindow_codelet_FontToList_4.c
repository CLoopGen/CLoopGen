#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '\0';
    unsigned int i;
    for (i = 0; font[i] != '\x00'; i++) {
        char curr = font[i];
        if ((curr == ':' && prev == ':') || 
            (curr == ';' && prev == ';') || 
            (curr == ',' && prev == ',')) {
            fonts++;
        }
        prev = curr;
    }
}
