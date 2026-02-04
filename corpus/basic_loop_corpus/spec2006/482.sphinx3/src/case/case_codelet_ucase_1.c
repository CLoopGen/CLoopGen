#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; *cp; cp++)
    *cp = ((((*cp) >= 'a') && ((*cp) <= 'z')) ? (*cp - 32) : *cp);

}
