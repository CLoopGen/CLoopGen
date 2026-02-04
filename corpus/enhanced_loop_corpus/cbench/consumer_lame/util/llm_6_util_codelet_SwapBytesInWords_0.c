#include <stdio.h>

#include <inttypes.h>

extern short *loc;
extern int words;
extern int i;
extern short thisval;
extern char *dst;
extern char *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short *local_loc = loc;
    char *local_dst;
    short temp_val;
    for (i = 0; i < words; i++) {
        temp_val = *local_loc;
        local_dst = (char *)local_loc;
        local_loc++;
        local_dst[0] = src[1];
        local_dst[1] = src[0];
    }
}
