#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b;
for (; s[i]; i++) {
    b = 1;
    for (j = 0; sep[j] && b; j++) { // Merged condition to reduce effective inner loop iterations logically
        b = (s[i] != sep[j]); // b becomes 0 if match found, exits inner loop
    }
    if (b) break; // No match was found in sep, so exit outer loop
}
}
