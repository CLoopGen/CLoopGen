#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *font;
extern char *p;
extern unsigned int fonts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = font;
    unsigned int local_fonts = 0;
    for (; *temp != '\x00'; temp++) {
        if ((*temp == ':') || (*temp == ';') || (*temp == ',')) {
            local_fonts++;
        }
    }
    fonts += local_fonts;
}
