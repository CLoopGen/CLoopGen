#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = content; (*p != ',') && (*p != '\x00') && (*(p+1) != '\x00'); p += 2) {
        if (*(p+1) == ',' || *(p+1) == '\x00') {
            p++;
            break;
        }
    }
    while ((*p != ',') && (*p != '\x00')) p++;
}
