#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_s = s + 2;
    e = temp_s;
    for (; *e; e++) {
        s = temp_s; // Introduce WAW dependency: write-after-write on 's'
    }
}
