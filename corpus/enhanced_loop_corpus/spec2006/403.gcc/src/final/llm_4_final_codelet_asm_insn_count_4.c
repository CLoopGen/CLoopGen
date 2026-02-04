#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *template; template++) {
        if (*template != ';' && *template != '\n') {
            continue;
        }
        count++;
    }
}
