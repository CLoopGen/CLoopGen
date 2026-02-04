#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    register int count = n >> 1;
    register char *left = s;
    register char *right = e;
    register char temp;
    for (; count > 0; count -= 2, left++, right--) {
        if (count >= 2) {
            temp = *left;
            *left = *right;
            *right = temp;
            temp = *(left + 1);
            *(left + 1) = *(right - 1);
            *(right - 1) = temp;
        } else {
            temp = *left;
            *left = *right;
            *right = temp;
        }
    }
}
