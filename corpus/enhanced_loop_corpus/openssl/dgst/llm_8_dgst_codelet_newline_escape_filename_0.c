#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < length; i += step) {
        if (file[i] == '\n')
            newline_count++;
        if ((i + 1) < length && file[i + 1] == '\n')
            newline_count++;
    }
}
