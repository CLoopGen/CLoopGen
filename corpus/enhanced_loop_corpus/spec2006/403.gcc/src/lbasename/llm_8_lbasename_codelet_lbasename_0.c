#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = name;
    base = name;
    for (; *ptr; ptr++) {
        if ((*ptr == '/') && (ptr[1] != '\0')) {
            base = ptr + 1;
        }
    }
}
