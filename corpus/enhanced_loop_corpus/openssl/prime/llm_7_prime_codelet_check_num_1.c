#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp;
    for (i = 0; '0' <= s[i] && s[i] <= '9'; i++) {
        temp = s[i] - '0'; // Introduce RAW dependency: read s[i] before computing temp
        s[i] = temp + '0'; // Introduce WAR/WAW: write to s[i] creates anti and output dependence
    }
}
