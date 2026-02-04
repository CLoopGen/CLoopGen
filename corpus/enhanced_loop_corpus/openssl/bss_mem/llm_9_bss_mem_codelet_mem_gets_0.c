#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < j * 2; i++) {
        if (i % 2 == 0 && p[i / 2] == '\n') {
            i++;
            break;
        }
    }
}
