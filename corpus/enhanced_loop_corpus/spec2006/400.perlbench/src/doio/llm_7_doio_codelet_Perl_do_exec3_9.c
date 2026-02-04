#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int32_t idx = 0;
    char *local_s = PL_Cmd;
    char **local_a = a;
    char prev = '\x00';

    for (idx = 0; local_s[idx]; ++idx) {
        if ((local_s[idx] != ' ' && local_s[idx] != '\t' && local_s[idx] != '\n' &&
             local_s[idx] != '\r' && local_s[idx] != '\f') &&
            (prev == ' ' || prev == '\t' || prev == '\n' || prev == '\r' ||
             prev == '\f' || prev == '\x00')) {
            local_a[0] = &local_s[idx];
            local_a++;
        }

        if ((local_s[idx] == ' ' || local_s[idx] == '\t' || local_s[idx] == '\n' ||
             local_s[idx] == '\r' || local_s[idx] == '\f') && prev != '\x00' &&
            prev != ' ' && prev != '\t' && prev != '\n' && prev != '\r' && prev != '\f') {
            local_s[idx] = '\x00';
        }

        prev = local_s[idx];
    }

    a = local_a;
    s = &local_s[idx];
}
