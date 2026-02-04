#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds s;
extern  char *from;
extern  char *to;
extern size_t setlen;
extern size_t j;
extern size_t i;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < l; j++) {
        size_t found = 0;
        for (i = 0; i < setlen && !found; i++) {
            if (s[j] == from[i]) {
                s[j] = to[i];
                found = 1;
            }
        }
    }
}
