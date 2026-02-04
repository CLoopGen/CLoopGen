#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; k++)
        for (j = i; j <= argc; j++)
            argv[j] = argv[j + off];
}
