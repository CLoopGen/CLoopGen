#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (v = 0; v <= 255; ++v) {
        int next = prev + v; // RAW dependency: read 'prev' before writing 'next'
        prev = next;         // Loop-carried dependency: each iteration depends on the previous
    }
    v = prev;
}
