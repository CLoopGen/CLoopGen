#include <stdio.h>

#include <inttypes.h>

extern int *uid_luid;
extern int max_uid_for_loop;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = max_uid_for_loop - 1; i >= 0; i--) {
    uid_luid[0] = uid_luid[i];
    if (uid_luid[0] != 0)
        break;
}
}
