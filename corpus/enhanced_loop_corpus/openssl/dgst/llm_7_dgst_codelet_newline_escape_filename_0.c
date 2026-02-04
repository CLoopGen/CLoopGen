#include <stdio.h>

#include <inttypes.h>

extern  char *file;
extern size_t i;
extern size_t length;
extern size_t newline_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_newline_count = 0;
    for (i = 0; i < length; i += 2) {
        if (i + 1 < length) {
            local_newline_count += (file[i] == '\n') + (file[i + 1] == '\n');
        } else {
            local_newline_count += (file[i] == '\n');
        }
    }
    newline_count = local_newline_count;
}
