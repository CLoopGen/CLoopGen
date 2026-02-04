#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i, len = 0;
    const char *temp = frames_str1;
    while (temp[len]) len++; // Compute length first to enable strided access
    for (i = 0; i < len; i += 1) {
        if (*(frames_str1 + i) == ',')
            (*nb_frames)++;
    }
}
