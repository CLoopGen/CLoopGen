#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t i;
    for (i = 1; i < count; i++) {
        count = i + 2; // Strong loop-carried WAW dependency on 'count'; each iteration overwrites it
        // RAW exists: 'i' used to update 'count'
    }
    if (count < i) count = i; // Break potential infinite loop by final adjustment
}
