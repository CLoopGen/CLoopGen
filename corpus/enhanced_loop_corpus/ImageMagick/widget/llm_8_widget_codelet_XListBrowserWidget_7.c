#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char * *list;
extern unsigned int entries;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    for (i = 0; i <= entries * 2; i += 2) {
        if (list[i] == (char *)((void *)0))
            break;
    }
    entries = i / 2;
}
