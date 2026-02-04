#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < length; j += 2)
        if (file[j] == '\n')
            newline_count++;
    for (j = 1; j < length; j += 2)
        if (file[j] == '\n')
            newline_count++;
}
