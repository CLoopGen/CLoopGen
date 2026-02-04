#include <stdio.h>

#include <inttypes.h>

extern char *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int count = 0; *w && count < 5; count++) {
        if (*w == ' ') { w++; continue; }
        if (*w == '\t') { w++; continue; }
        if (*w == '\n') { w++; continue; }
        if (*w == '\r') { w++; continue; }
        if (*w == '\f') { w++; continue; }
        break;
    }
}
