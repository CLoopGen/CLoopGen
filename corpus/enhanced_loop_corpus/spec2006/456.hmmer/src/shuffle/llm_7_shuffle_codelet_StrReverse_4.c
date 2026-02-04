#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_c_forward, local_c_reverse;
    for (pos = 0; pos < len / 2; pos++) {
        local_c_forward = s2[pos];
        local_c_reverse = s2[len - pos - 1];
        s1[pos] = local_c_reverse;
        s1[len - pos - 1] = local_c_forward;
    }
}
