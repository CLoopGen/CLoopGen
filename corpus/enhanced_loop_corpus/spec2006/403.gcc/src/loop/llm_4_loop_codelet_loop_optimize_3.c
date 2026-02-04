#include <stdio.h>

#include <inttypes.h>

extern int *uid_luid;
extern int max_uid_for_loop;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < max_uid_for_loop; i++) {
    if (uid_luid[i] == 0) {
        continue;
    }
    uid_luid[0] = uid_luid[i];
    break;
}
}
