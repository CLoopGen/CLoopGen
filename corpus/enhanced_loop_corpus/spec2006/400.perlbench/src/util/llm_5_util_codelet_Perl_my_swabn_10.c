#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n /= 2; n > 0; s++ , e-- , n--) {
    if (*s == *e) continue;
    tc = *s;
    *s = *e;
    *e = tc;
}
}
