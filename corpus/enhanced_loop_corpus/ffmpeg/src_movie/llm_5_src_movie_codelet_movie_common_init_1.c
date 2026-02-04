#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int should_count = 0;
    for (cursor = stream_specs; *cursor; cursor++) {
        should_count = (*cursor == '+');
        if (should_count)
            nb_streams++;
    }
}
