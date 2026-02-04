#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *local_x = big;
    char *local_s = little;
    int match = 1;
    
    for (; match && local_s < littleend; ) {
        match = (*local_s == *local_x);
        local_s += match;
        local_x += match;
    }
    if (!match) {
        local_s--;
    }
    s = local_s;
    x = local_x;
}
