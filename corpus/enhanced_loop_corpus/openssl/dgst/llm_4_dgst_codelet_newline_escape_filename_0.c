#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        newline_count += (file[i] == '\n');
    }
}
