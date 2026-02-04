#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char * *list;
extern unsigned int entries;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i = 0;
    char *temp;

    for (entries = 0; i < 1 || temp != (char *)((void *)0); i++) {
        temp = list[entries];
        entries++;
        if (temp == (char *)((void *)0))
            break;
    }
}
