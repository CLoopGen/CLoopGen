#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using an index derived from s2 and s1
    int i;
    for (i = 0; s1 + i <= s2; i++) {
        int idx = s2 - i;  // Traverse from s2 down to s1 consecutively
        kassign[idx] = 1;
        tassign[idx] = 5;
    }
}
