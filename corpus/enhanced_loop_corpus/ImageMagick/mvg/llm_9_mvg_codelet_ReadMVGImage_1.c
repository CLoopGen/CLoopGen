#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char primitive[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = primitive; (*p == ' ') || (*p == '\t') || (*p == '\n') || (*p == '\r'); p += 1) {
        if ((p - primitive) >= 512) break;
    }
}
