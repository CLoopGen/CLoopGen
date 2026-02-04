#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (; ; temp++) {
        char *current = args[temp];
        if (current == (char *)((void *)0)) {
            arg_count = temp;
            goto end;
        }
    }
    end: ;
}
