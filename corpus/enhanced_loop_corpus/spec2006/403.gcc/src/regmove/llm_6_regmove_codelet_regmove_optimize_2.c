#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = old_max_uid; i >= 0; i--) {
        temp = regmove_bb_head[i];
        regmove_bb_head[i] = temp - 1;
    }
}
