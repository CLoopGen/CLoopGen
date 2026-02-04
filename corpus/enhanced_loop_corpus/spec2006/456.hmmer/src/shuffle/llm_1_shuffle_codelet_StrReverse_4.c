#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        for (pos = 0; pos < len / 2; pos += 2) {
            c = s2[len - pos - 1];
            s1[len - pos - 1] = s2[pos];
            s1[pos] = c;

            if (pos + 1 < len / 2) {
                c = s2[len - pos - 2];
                s1[len - pos - 2] = s2[pos + 1];
                s1[pos + 1] = c;
            }
        }
    }
}
