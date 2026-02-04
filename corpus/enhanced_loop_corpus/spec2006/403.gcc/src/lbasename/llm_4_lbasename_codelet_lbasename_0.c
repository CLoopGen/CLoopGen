#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (base = name; *name; name++) {
        if (*name != '/') 
            continue;
        base = name + 1;
    }
}
