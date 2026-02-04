#include <stdio.h>

#include <inttypes.h>

extern  char *elem;
extern int len;
extern int i;
extern int vlen;
extern  char *p;
extern  char *vstart;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = elem;
    int temp_i = 0;
    char *found_pos = NULL;

    for (i = 0; i < len; i++, temp_p++) {
        if (*temp_p == ':') {
            found_pos = temp_p;
            break;
        }
    }

    if (found_pos != NULL) {
        vstart = found_pos + 1;
        vlen = len - (int)(vstart - elem);
        len = (int)(found_pos - elem);
    }

    p = temp_p;
}
