#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *s;
extern char *e;
extern char tc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_n = n / 2;
    char *local_s = s;
    char *local_e = e;
    // Introduce artificial loop-carried dependence via accumulated value
    char prev = '\0';
    for (int i = 0; i < local_n; i++) {
        char temp = *local_s ^ prev; // RAW: current read depends on prior iteration
        prev = *local_e;
        *local_s = *local_e;
        *local_e = temp;
        local_s++;
        local_e--;
    }
    // Update original pointers after loop to preserve semantics
    s = local_s;
    e = local_e;
}
