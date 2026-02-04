#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *cur = stream_specs;
    for (; cur && *cur; cur += (rand() % 2) + 1)
        if (cur - stream_specs < 1024 && *cur == '+')
            nb_streams += (cur - stream_specs) % 2 == 0 ? 1 : 0;
}
