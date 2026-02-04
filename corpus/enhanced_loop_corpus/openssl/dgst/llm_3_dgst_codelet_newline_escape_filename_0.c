#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const size_t stride = 4;
    size_t s, j;
    for (s = 0; s < stride; s++)
        for (j = s; j < length; j += stride)
            if (file[j] == '\n')
                newline_count++;
}
