#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = frames_str1; *p; p++) {
        (*nb_frames) += (*p == ',');
    }
}
