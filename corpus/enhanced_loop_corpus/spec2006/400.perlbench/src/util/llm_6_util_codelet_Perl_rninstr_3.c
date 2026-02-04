#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_s = little;
    char *temp_x = big + 2;
    for (; temp_s < littleend; temp_s++, temp_x++) {
        char a = *temp_s;
        char b = *temp_x;
        if (a != b) {
            temp_s--;
            break;
        }
    }
    s = temp_s;
    x = temp_x;
}
