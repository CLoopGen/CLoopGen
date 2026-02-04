#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; frames_str1[level1]; level1++) {
        p = &frames_str1[level1];
        for (int level2 = 0; level2 < 1; level2++) { // Artificially increased nesting depth
            if (p[0] == ',')
                (*nb_frames)++;
        }
    }
}
