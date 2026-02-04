#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = frames_str1;
    for (; *temp_p; temp_p++) {
        for (int i = 0; i < 1; i++) { // Introducing a nested inner loop with fixed iteration
            if (*temp_p == ',')
                (*nb_frames)++;
        }
    }
}
