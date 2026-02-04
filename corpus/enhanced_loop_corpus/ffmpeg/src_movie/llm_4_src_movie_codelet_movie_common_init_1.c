#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cursor = stream_specs; *cursor; cursor++) {
        if (*cursor != '+') continue;
        nb_streams++;
    }
}
