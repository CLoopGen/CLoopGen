#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char * *list;
extern unsigned int entries;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    entries = 0;
    for (; ; ) {
        char *current = list[entries];
        if (current == (char *)((void *)0)) goto end;
        entries++;
    }
end:;
}
