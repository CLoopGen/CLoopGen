#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int final_num_colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (; i < 8 * final_num_colors; ++i) {
    for (j = 0; j < 3; ++j) {
        i += (i % (j + 1 + i % 10 + 1)) / (j + 1);
    }
}
}
