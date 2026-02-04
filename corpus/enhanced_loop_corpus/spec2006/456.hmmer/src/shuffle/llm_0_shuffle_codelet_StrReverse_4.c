#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < len / 2; i++) {
        for (pos = i; pos <= i; pos++) {
            c = s2[len - pos - 1];
            s1[len - pos - 1] = s2[pos];
            s1[pos] = c;
        }
    }
}
