#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = str;
    size_t local_maxlen = maxlen;
    for (p = temp; local_maxlen != 0 && *temp != '\x00'; ++temp, --local_maxlen) {
        p = temp + 1; // Introduce WAW dependency on p and RAW on temp
    }
    if (p != str) p--; // Adjust final value of p to match original semantics when exiting loop
}
