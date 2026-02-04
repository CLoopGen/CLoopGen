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
    for (j = 0; j < l; j += 2) {
        for (i = 0; i < setlen; i++) {
            if (j < l && s[j] == from[i]) {
                s[j] = to[i];
                break;
            }
        }
        if (j + 1 < l) {
            for (i = 0; i < setlen; i++) {
                if (s[j + 1] == from[i]) {
                    s[j + 1] = to[i];
                    break;
                }
            }
        }
    }
}
