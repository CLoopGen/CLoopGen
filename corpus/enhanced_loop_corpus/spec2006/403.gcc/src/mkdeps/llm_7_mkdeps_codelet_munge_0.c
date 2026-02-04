#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *local_p;
    int local_len;

    for (local_p = filename, local_len = 0; *local_p; ) {
        switch (*local_p) {
            case ' ':
            case '\t':
                {
                    char *q = local_p - 1;
                    int backslash_count = 0;
                    while (filename <= q && *q == '\\') {
                        backslash_count++;
                        q--;
                    }
                    local_len += 2 + backslash_count;
                }
                break;
            case '$':
                local_len += 2;
                local_p++;
                continue;
            default:
                local_len++;
                local_p++;
                continue;
        }
        local_p++;
    }

    p = local_p;
    len = local_len;
}
