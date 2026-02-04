#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    fonts = 0;
    for (p = font; *p != '\x00'; p++) {
        unsigned int diff1 = *p - ':';
        unsigned int diff2 = *p - ';';
        unsigned int diff3 = *p - ',';
        if ((diff1 == 0) || (diff2 == 0) || (diff3 == 0))
            fonts++;
    }
}
