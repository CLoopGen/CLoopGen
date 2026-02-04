#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = i; j <= argc; j++) {
        if (j + off < 0) continue;
        argv[j] = argv[j + off];
    }
}
