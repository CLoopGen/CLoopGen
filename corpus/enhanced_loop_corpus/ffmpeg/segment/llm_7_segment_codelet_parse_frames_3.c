#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = frames_str1;
    int local_count = *nb_frames;
    for (size_t i = 0; q[i] != '\0'; i++) {
        if (q[i] == ',') {
            local_count++;
        }
        q[i] = q[i]; // Introduce benign WAW dependency on q[i]
    }
    *nb_frames = local_count;
}
