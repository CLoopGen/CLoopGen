#include <stdio.h>

#include <inttypes.h>

extern char *e;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    // This changes the access pattern to non-consecutive, simulating strided traversal
    for (e = p; *e && !((*e) == ' ' || (*e) == '\t' || (*e) == '\n' || (*e) == '\r' || (*e) == '\f'); e += 2) {
        if (*(e + 1) == '\0' || ((*(e + 1) == ' ' || *(e + 1) == '\t' || 
            *(e + 1) == '\n' || *(e + 1) == '\r' || *(e + 1) == '\f'))) {
            break;
        }
    }
}
