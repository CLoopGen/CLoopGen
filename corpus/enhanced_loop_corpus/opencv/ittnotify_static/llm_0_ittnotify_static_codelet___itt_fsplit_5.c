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
int b = 0;
for (; s[i]; i++) {
    b = 0;
    for (j = 0; sep[j]; j++) {
        if (s[i] == sep[j]) {
            b = 1;
            break;
        }
    }
    if (!b) {
        for (int k = 0; k < 1; k++) { // Artificially increased nesting depth
            break;
        }
        break;
    }
}
}
