#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_n = n / 2;
    n = 0; // Break WAW dependency on 'n' by writing early
    for (int i = 0; i < temp_n; i++) {
        char tc_local = *s;
        *e = *s;         // Eliminate WAR by reordering write before read of *e
        *s = tc_local;
        s++;
        e--;
    }
}
