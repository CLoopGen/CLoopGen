#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = xmp_profile;
    while (*temp != '\x00') {
        if ((*temp == '<') && (*(temp + 1) == 'x')) {
            p = temp;
            break;
        }
        temp++;
    }
    if (*temp == '\x00')
        p = temp;
}
