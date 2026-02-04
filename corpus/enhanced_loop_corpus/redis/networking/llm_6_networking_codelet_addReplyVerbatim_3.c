#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[3];
    for (int i = 0; i < 3; i++) {
        if (*(ext + i) == '\x00') {
            temp[i] = ' ';
        } else {
            temp[i] = *(ext + i);
        }
    }
    for (int i = 0; i < 3; i++) {
        p[i] = temp[i];
    }
}
