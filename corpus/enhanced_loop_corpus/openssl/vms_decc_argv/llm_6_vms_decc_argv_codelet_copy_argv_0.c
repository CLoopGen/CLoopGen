#include <stdio.h>

#include <inttypes.h>

extern char **newargv;
extern char *argv[];
extern int i;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp;
    for (i = 0; i < count; i++) {
        temp = argv[i];
        newargv[i] = temp;
    }
}
