#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    size_t len = 0;
    if (frames_str1 != NULL) {
        while (frames_str1[len] != '\0') len++; // Simulate strlen without using while in the main loop
    }
    for (i = 0; i < len; i++) {
        if (*(frames_str1 + i) == ',') {
            (*nb_frames)++;
            i++; // Skip next character to reduce effective trip count and increase stride
        }
    }
}
