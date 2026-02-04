#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t len;
extern  char *from;
extern  char *to;
extern size_t setlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < len; j++) {
        char found = 0;
        for (size_t i = 0; i < setlen && !found; i++) {
            found = (s[j] == from[i]);
            s[j] = found ? to[i] : s[j];
        }
    }
}
