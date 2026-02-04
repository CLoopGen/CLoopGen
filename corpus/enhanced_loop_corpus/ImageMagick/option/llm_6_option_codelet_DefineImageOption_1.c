#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = key;
    char found = 0;
    for (; !found && *temp != '\x00'; temp++) {
        found = (*temp == '=');
    }
    p = found ? temp - 1 : temp;
}
