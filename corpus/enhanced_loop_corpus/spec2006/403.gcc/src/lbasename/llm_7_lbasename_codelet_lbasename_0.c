#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = name;
    while (*temp) temp++; // Compute end once — no loop-carried dependency on base
    char *last_slash = name;
    for (char *p = name; p < temp; p++) {
        if ((*p) == '/') {
            last_slash = p + 1; // Introduce WAW: last_slash overwritten each time
        }
    }
    base = last_slash;
}
