#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = big + 2 , s = little; s < littleend;) {
    if (*s++ != *x++) {
        s--;
        break;
    }
}

}
