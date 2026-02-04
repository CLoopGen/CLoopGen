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
    char temp;
    for (j = 0; j < l; j++) {
        temp = s[j];
        for (i = 0; i < setlen; i++) {
            if (temp == from[i]) {
                temp = to[i];
                break;
            }
        }
        s[j] = temp;
    }
}
