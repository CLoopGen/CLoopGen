#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; tmpval > 9; ) {
        len++;
        tmpval /= 10;
        if (!(tmpval > 9)) break;
    }
}
