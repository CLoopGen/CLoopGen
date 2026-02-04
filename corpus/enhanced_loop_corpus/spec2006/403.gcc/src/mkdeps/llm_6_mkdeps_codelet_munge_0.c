#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *temp_p = filename;
    int temp_len = 0;
    char prev_char = '\0';

    for (; *temp_p; temp_p++, temp_len++) {
        switch (*temp_p) {
            case ' ':
            case '\t':
                {
                    char *q = temp_p - 1;
                    while (filename <= q && *q == '\\') {
                        temp_len++;
                        q--;
                    }
                    temp_len++;
                }
                break;
            case '$':
                temp_len++;
                break;
        }
        prev_char = *temp_p;
    }
    p = temp_p;
    len = temp_len;
}
