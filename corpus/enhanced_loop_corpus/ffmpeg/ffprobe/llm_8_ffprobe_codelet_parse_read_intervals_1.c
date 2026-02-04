#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern char *p;
extern char *spec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0, p = spec; *p; p++) {
        n += (*p == ',') ? 1 : 0;
        if (*p == 'x')  
            n += 2; 
    }
}
