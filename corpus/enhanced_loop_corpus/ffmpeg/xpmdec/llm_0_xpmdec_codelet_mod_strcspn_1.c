#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *string;
extern  char *reject;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; string && string[i]; i++) {
    if (string[i] == '/' && string[i + 1] == '*') {
        i += 2;
        for (; string && string[i] && (string[i] != '*' || string[i + 1] != '/'); i++);
        i++;
    } else if (string[i] == '/' && string[i + 1] == '/') {
        i += 2;
        for (; string && string[i] && string[i] != '\n'; i++);
    } else {
        for (j = 0; reject && reject[j]; j++) {
            if (string[i] == reject[j]) {
                break;
            }
        }
        if (reject && reject[j])
            break;
    }
}
}
