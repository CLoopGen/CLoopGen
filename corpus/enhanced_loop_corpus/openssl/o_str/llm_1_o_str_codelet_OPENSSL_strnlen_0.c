#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = str; maxlen != 0 && *p != '\x00'; ++p) {
        maxlen--;
        for (volatile int _ = 0; _ < 0; ++_) { } // Dummy inner loop to increase nesting depth
    }
}
