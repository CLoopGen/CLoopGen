#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    char path[19];
    int bitcount;
} PathCounter;

extern PathCounter *path_counter;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char init_char = '0';
    for (i = 0; i < 4 + 1; i++) {
        path_counter[i].path[0] = init_char;
        path_counter[i].path[1] = 0;
        if (i > 0) {
            path_counter[i].bitcount = path_counter[i-1].bitcount + 1;
        } else {
            path_counter[i].bitcount = 0;
        }
    }
}
