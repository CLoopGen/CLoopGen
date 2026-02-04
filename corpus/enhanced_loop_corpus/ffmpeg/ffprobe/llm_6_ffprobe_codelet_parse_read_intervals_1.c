#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern char *p;
extern char *spec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_n = 0;
    for (p = spec; *p; p++) {
        temp_n += (*p == ',');
    }
    n = temp_n;
}
