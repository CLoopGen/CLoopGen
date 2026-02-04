#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t step = 1;
    char *end = stream_specs;
    while (*end) end++;
    for (char *pos = stream_specs; pos < end; pos += step)
        if (*(pos + 0) == '+')
            nb_streams++;
}
