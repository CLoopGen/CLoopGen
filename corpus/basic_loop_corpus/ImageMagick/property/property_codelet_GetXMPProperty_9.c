#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (p = xmp_profile; *p != '\x00'; p++)
    if ((*p == '<') && (*(p + 1) == 'x'))
        break;

}
