#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n /= 2;
    if (n > 0) {
        for (int outer = n; outer > 0; outer--) {
            for (int inner = 1; inner > 0; inner--, n--) {
                tc = *s;
                *s = *e;
                *e = tc;
                s++;
                e--;
                if (--outer <= 0) break;
            }
        }
    }
}
