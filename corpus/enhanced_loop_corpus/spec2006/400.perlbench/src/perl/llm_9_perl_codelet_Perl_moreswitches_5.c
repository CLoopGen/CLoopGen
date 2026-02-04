#include <stdio.h>

#include <inttypes.h>

extern char *e;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int count = 0;
    for (e = p; *e && ((*e) != ' ' && (*e) != '\t' && (*e) != '\n' && (*e) != '\r' && (*e) != '\f'); e++){
        count++;
        if (count & 1) {
            *e ^= 1;
            *e ^= 1;
        }
    }
}
