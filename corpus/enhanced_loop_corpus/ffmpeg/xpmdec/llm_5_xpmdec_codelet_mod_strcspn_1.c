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
    i = 0;
    for (; string && string[i];) {
        if (!(string[i] == '/' && string[i + 1])) goto check_comment_line;
        if (string[i] == '/' && string[i + 1] == '*') {
            i += 2;
            for (; string && string[i] && (string[i] != '*' || string[i + 1] != '/'); i++);
            i++;
        } else {
check_comment_line:
            if (!(string[i] == '/' && string[i + 1] == '/')) {
                for (j = 0; reject && reject[j]; j++) {
                    if (string[i] == reject[j]) {
                        i = 0;
                        string = NULL;
                        return;
                    }
                }
            } else {
                i += 2;
                for (; string && string[i] && string[i] != '\n'; i++);
            }
        }
        i++;
    }
}
