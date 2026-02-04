#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char primitive[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = primitive;
    for (; (*temp == ' ') || (*temp == '\t'); temp++) {
        p = temp + 1;
    }
    if (p == NULL) {
        p = primitive;
    }
}
