#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long prev = 0;
    for (i = 0; i < out_len; i++) {
        out[i] = prev;       // WAW and WAR hazard avoided by writing only once per element; introduces loop-carried dependency
        prev = out[i] + 1;   // RAW dependency: depends on current value of out[i] just written
    }
}
