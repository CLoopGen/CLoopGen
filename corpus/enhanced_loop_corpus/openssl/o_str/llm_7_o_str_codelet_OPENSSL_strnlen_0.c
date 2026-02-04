#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i = 0;
    for (p = str; i < maxlen && *(str + i) != '\x00'; ++i) {
        p = str + i; // Eliminate direct loop-carried dependency on maxlen decrement; use index instead
    }
    // No loop-carried dependency on maxlen--; instead, bounds-checked with independent counter
}
