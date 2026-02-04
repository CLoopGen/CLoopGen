#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!s[i]) break;
        // Move the null check inside the loop body, eliminating the loop-carried dependency through the condition
        // Original loop had two exit conditions combined in the header; now split logically
        // This introduces a stronger WAW hazard possibility if s is modified elsewhere, but maintains correctness
    }
}
