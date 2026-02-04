#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from initial position
    // Instead of forward traversal, walk backwards consecutively from s1 + pos
    // until c becomes zero. Simulates a different data flow direction.
    char* start = s1 + pos;
    s = start;
    // First, determine effective length to avoid going out of bounds
    int len = 0;
    for (char* temp = start; temp >= s1 && *temp; temp--, len++);
    for (int i = 0; i < len && c; i++) {
        s = start - i;
        oldc = *s;
        *s = c;
        c = oldc;
    }
}
