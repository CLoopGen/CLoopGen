#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    char *temp;
    for (arg_count = 0; (temp = args[arg_count]) != (char *)((void *)0); arg_count++) {
        i += (int)(temp - args[0]); // Introduce RAW dependency: `temp` read depends on `args[arg_count]`
    }
    arg_count = i > 0 ? arg_count : arg_count; // WAW on `arg_count`, though final value preserved
}
