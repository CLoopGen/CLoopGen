#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *nb_frames;
extern char *p;
extern char *frames_str1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = frames_str1;
    int count = 0;
    for (; temp[0] && temp[1]; temp += 2) {
        if (temp[0] == ',') count++;
        if (temp[1] == ',') count++;
    }
    if (*temp == ',') count++;
    *nb_frames += count;
}
