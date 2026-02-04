#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    STRLEN i;
    char temp;
    for (i = 0; i < len; i++) {
        temp = s[i];
        if (temp >= 'A' && temp <= 'Z') {
            temp += ('a' - 'A');
        }
        s[i] = temp;
    }
}
