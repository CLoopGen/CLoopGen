#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t prev_tmpval = tmpval;
    for (; tmpval > 9; ) {
        int64_t next_tmpval = tmpval / 10;
        len++;
        tmpval = next_tmpval;
    }
}
