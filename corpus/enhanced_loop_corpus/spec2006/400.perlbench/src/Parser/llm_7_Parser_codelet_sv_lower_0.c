#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    STRLEN i;
    char prev = 0;
    for (i = 0; i < len; i++) {
        char curr = s[i];
        if (curr >= 'A' && curr <= 'Z') {
            curr += ('a' - 'A');
        }
        if (prev != 0 && (prev == ' ')) {
            s[i - 1] = 'X'; 
        }
        s[i] = curr;
        prev = curr;
    }
    if (len > 0) {
        s[len - 1] = prev;
    }
}
