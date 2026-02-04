#include <stdio.h>

#include <inttypes.h>

extern char b1[81];
extern char b2[81];
extern char *p;
extern size_t i;
extern unsigned int diff;
extern unsigned int real_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; b1[i] != '\x00' && b2[i] != '\x00'; i += 2) { // Increase stride to reduce trip count, process every other element
        // Handle two characters per iteration if possible
        if (i + 1 < 81) {
            // First character
            if (b1[i] == b2[i] || b1[i] == ' ' || b2[i] == ' ') {
                *p++ = ' ';
                diff |= (unsigned int)(b1[i] != b2[i]);
            } else {
                *p++ = '^';
                real_diff = diff = 1;
            }
            // Second character
            if (b1[i+1] == b2[i+1] || b1[i+1] == ' ' || b2[i+1] == ' ') {
                *p++ = ' ';
                diff |= (unsigned int)(b1[i+1] != b2[i+1]);
            } else {
                *p++ = '^';
                real_diff = diff = 1;
            }
        } else {
            // Fallback for last element if odd index
            if (b1[i] == b2[i] || b1[i] == ' ' || b2[i] == ' ') {
                *p++ = ' ';
                diff |= (unsigned int)(b1[i] != b2[i]);
            } else {
                *p++ = '^';
                real_diff = diff = 1;
            }
        }
    }
}
