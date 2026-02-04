#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (arg_count = 0; ; arg_count++) {
        if (args[arg_count] == (char *)((void *)0))
            break;
    }
}
