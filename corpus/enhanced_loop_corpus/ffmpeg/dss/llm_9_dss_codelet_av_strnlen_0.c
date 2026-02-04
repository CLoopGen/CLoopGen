#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t count = 0;
    const size_t threshold = 8;
    for (; i < len && s[i] && count < threshold; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            count++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            count += 2;
        else
            count = (count + 1) / 2;
    }
}
