#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = name;
    char *local_base = base;
    for (; *ptr; ptr++) {
        if ((*ptr) == '/') {
            local_base = ptr + 1;
        }
    }
    base = local_base;
}
