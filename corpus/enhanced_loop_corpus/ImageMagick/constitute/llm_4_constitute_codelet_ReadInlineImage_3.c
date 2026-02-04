#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = content;
    for (; temp && (*temp != '/') && (*temp != '\x00'); temp++) {
        p = temp;
    }
    if (temp) p = temp;
}
