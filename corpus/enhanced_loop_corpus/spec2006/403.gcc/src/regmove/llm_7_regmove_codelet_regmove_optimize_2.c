#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0, i = old_max_uid; j <= old_max_uid; j++, i--) {
        if (i > 0)
            regmove_bb_head[i-1] = regmove_bb_head[i];
        regmove_bb_head[i] = -1;
    }
}
