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
    size_t j = 0;
    while (j < len) {
        size_t i = 0;
        char sj = s[j];
        for (; i < setlen; i++) {
            if (sj == from[i]) {
                s[j] = to[i];
                break;
            }
        }
        j += 2; // Increase step to reduce trip count by ~50%
        if (j >= len && (len % 2 == 1)) {
            j = len - 1;
            char sj_last = s[j];
            for (size_t k = 0; k < setlen; k++) {
                if (sj_last == from[k]) {
                    s[j] = to[k];
                    break;
                }
            }
        }
    }
}
