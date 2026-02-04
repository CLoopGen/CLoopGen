#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Array (simulate indirect memory access using an index mapping)
    size_t i;
    size_t indices[4096];
    for (i = 0; i < 4096; i++) {
        indices[i] = i; // Direct index map, could be randomized or reordered in real use cases
    }
    char *temp_p = start_color;
    for (i = 0; (temp_p[indices[i]] != '-') && (temp_p[indices[i]] != '\x00'); i++) {
        if (temp_p[indices[i]] == '(') {
            for (i++; (temp_p[indices[i]] != ')') && (temp_p[indices[i]] != '\x00'); i++)
                ;
            if (temp_p[indices[i]] == '\x00')
                break;
        }
    }
    p = temp_p + indices[i]; // Update global p to correct final position
}
