#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = font;
    fonts = 0;
    for (; temp_p[0] != '\x00' && temp_p[1] != '\x00'; temp_p += 2) {
        if ((temp_p[0] == ':') || (temp_p[0] == ';') || (temp_p[0] == ','))
            fonts++;
        if ((temp_p[1] == ':') || (temp_p[1] == ';') || (temp_p[1] == ','))
            fonts++;
    }
    // Handle last character if odd length
    if (*temp_p != '\x00') {
        if ((*temp_p == ':') || (*temp_p == ';') || (*temp_p == ','))
            fonts++;
    }
}
