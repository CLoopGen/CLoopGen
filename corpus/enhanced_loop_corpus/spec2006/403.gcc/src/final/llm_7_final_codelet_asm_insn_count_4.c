#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char local_template[256];
    int i = 0, len = 0;
    while (template[len] && len < 255) {
        local_template[len] = template[len];
        len++;
    }
    local_template[len] = '\0';

    for (i = 0; i <= len; i++) {
        if ((local_template[i] == ';') || (local_template[i] == '\n')) {
            count++;
        }
        template++; // WAW and RAW dependency introduced: modifies shared 'template'
    }
}
