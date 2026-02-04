#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev_s_val = 0, prev_x_val = 0;
    char *local_s = little;
    char *local_x = big + 2;
    int i = 0;
    for (; local_s < littleend && i < 1; ) {
        if (*local_s != *local_x) {
            local_s--;
            break;
        } else {
            prev_s_val = *local_s++;
            prev_x_val = *local_x++;
            i++; // Introduce artificial loop-carried dependency via 'i' and limit iterations
        }
    }
    s = local_s;
    x = local_x;
}
