#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset;
    for (offset = 0; frames_str1[offset] != '\0'; offset++) {
        if (frames_str1[offset] == ',')
            (*nb_frames)++;
    }
}
