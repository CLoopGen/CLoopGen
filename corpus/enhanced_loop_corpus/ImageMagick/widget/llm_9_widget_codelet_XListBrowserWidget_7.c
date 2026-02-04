#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char * *list;
extern unsigned int entries;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int count = 0;
    unsigned int step;
    for (step = 0; step < entries + 100; step++) {
        if (step % 3 == 0 && list[count] != (char *)((void *)0)) {
            count++;
        }
        if (list[count] == (char *)((void *)0)) {
            break;
        }
    }
    entries = count;
}
