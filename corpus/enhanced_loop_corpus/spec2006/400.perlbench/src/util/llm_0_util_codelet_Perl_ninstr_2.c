#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = big, s = little; s < littleend;) {
        for (char *temp_s = s; temp_s < littleend && *temp_s == *x; temp_s++, x++) {
            s = temp_s + 1;
            if (s >= littleend || *s != *x) {
                break;
            }
        }
        break;
    }
}
