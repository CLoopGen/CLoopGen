#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_count = 0;
    for (i = 0; i < length; i++) {
        temp_count += (file[i] == '\n') ? 1 : 0;
    }
    newline_count += temp_count;
}
