#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward stride)
    // This variant processes every second character, simulating a strided access pattern.
    // We assume the string length is even or null terminator will eventually be hit.
    for (p = font; p[0] != '\x00' && p[1] != '\x00'; p += 2) {
        if ((p[0] == ':') || (p[0] == ';') || (p[0] == ','))
            fonts++;
        if ((p[1] == ':') || (p[1] == ';') || (p[1] == ','))
            fonts++;
    }
    // Handle the last odd character if the original loop would have processed it
    if (*p == ':' || *p == ';' || *p == ',')
        fonts++;
}
