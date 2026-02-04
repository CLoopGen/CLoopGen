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
        for (size_t k = 0; k < setlen; k += 2) {
            if (k + 1 < setlen) {
                if (s[j] == from[k]) {
                    s[j] = to[k];
                    break;
                } else if (s[j] == from[k + 1]) {
                    s[j] = to[k + 1];
                    break;
                }
            } else {
                if (s[j] == from[k]) {
                    s[j] = to[k];
                    break;
                }
            }
        }
    }
}
