#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_count = 0;
    char *ptr = stream_specs;
    for (; *ptr; ptr++) {
        if (*ptr == '+') {
            temp_count++;
        }
    }
    nb_streams += temp_count;
}
