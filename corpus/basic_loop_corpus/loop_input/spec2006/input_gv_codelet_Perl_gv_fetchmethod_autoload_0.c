#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;
char *nend;
char *nsplit;

static char data[1 << 20]; // 1MB buffer

void init_vars() {
    size_t len = sizeof(data) - 1; // Leave space for null terminator
    char *p = data;
    
    // Fill with mostly alphanumeric and some special characters
    for (size_t i = 0; i < len - 4; i++) {
        if ((i % 700) == 0 && i > 0) {
            *p++ = ':'; *p++ = ':'; i++;
        } else if ((i % 977) == 0 && i > 0) {
            *p++ = '\'';
        } else {
            *p++ = 'a' + (i % 26);
        }
    }
    *p = '\0';
    
    name = data;
    nend = data;
    nsplit = NULL;
}