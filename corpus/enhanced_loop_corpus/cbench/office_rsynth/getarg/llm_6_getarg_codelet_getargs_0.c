#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = i; k <= argc - off; k++) {
        argv[k] = argv[k + off];
    }
}
