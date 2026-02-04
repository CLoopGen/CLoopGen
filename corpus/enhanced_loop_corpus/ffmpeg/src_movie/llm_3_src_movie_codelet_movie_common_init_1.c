#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_streams;
extern char *stream_specs;
extern char *cursor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const char *base = stream_specs;
    size_t i;
    size_t len = 0;
    while (base[len]) len++;
    for (i = 0; i < len; i += 2) {
        if (base[i] == '+')
            nb_streams++;
    }
    for (i = 1; i < len; i += 2) {
        if (base[i] == '+')
            nb_streams++;
    }
}
