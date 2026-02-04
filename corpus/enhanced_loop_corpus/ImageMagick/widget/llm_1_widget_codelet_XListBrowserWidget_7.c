#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char * *list;
extern unsigned int entries;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (entries = 0; ; entries++) {
        if (list[entries] == (char *)((void *)0)) {
            break;
        } else {
            continue;
        }
    }
}
