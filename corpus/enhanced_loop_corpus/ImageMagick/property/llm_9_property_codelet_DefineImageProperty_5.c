#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = key;
    int count = 0;
    const int threshold = 100; // Artificially increase computational load
    for (p = key; *temp_p != '\x00' && count < threshold; temp_p++, count++) {
        if (*temp_p == '=') {
            p = temp_p;
            break;
        }
        // Add dummy operations to increase computational intensity
        count += (*temp_p & 1); // Slight arithmetic variation
        count -= (*temp_p & 1);
    }
    if (*temp_p == '\x00')
        p = temp_p;
}
