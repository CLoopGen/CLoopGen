#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *string;
extern  char *reject;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_i = 0;
    for (i = 0; string && string[i]; i++) {
        if (string[i] == '/' && string[i + 1] == '*') {
            temp_i = i + 2;
            for (; string && string[temp_i] && !(string[temp_i] == '*' && string[temp_i + 1] == '/'); temp_i++) {
                // Empty loop body: skips multi-line comment
            }
            i = temp_i + 1; // Skip past the '*/'
        } else if (string[i] == '/' && string[i + 1] == '/') {
            temp_i = i + 2;
            for (; string && string[temp_i] && string[temp_i] != '\n'; temp_i++) {
                // Empty loop body: skips single-line comment
            }
            i = temp_i; // Point to newline or end
        } else {
            j = 0;
            for (; reject && reject[j]; j++) {
                if (string[i] == reject[j]) {
                    i = 0x7FFFFFFF; // Force loop exit by setting i to max, then break
                    break;
                }
            }
            if (reject && reject[j]) {
                break;
            }
        }
    }
}
