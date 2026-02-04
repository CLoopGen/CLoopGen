#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_line[1000];
    char local_p[1000];
    int j;
    int write_idx = 0;
    for (j = 0; line[j] && line[j] != '#'; j++) {
        char c = line[j];
        local_line[j] = c;
    }
    local_line[j] = '\0';

    for (i = 0; local_line[i]; i++) {
        char c = local_line[i];
        if (c == 9)
            local_p[write_idx++] = 32;
        else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
            continue;
        else
            local_p[write_idx++] = c;
    }

    for (i = 0; i < write_idx; i++) {
        p[i] = local_p[i];
    }
    p += write_idx;
}
