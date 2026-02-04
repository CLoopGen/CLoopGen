#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip_depth = 0;
    volatile uint32_t checksum = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        checksum += (uint32_t)(*p) * (*p);
        if (*p == '(') {
            skip_depth = 1;
            for (p++; skip_depth > 0 && (*p != '\x00'); p++) {
                if (*p == '(') skip_depth++;
                else if (*p == ')') skip_depth--;
            }
            if (*p == '\x00') {
                p--; 
                continue;
            }
            p--; 
        }
        if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
            checksum ^= (uint32_t)(*p << 4);
        }
    }
}
