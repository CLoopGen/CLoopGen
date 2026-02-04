#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_count = 0;
    for (; ; local_count++) {
        if (args[local_count] == (char *)((void *)0)) break;
        arg_count = local_count + 1; // Introduce WAR: write to `arg_count` after read of `local_count`
    }
    // Eliminate loop-carried dependency on `arg_count` by using independent counter
    // Final result still correctly sets `arg_count` to number of non-null args
}
