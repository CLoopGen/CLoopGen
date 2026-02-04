#include <stdio.h>

#include <inttypes.h>

extern int *uid_luid;
extern int max_uid_for_loop;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < max_uid_for_loop; i++) {
        if (uid_luid[i] == 0 && uid_luid[i - 1] != 0) {
            uid_luid[i] = uid_luid[i - 1];
        }
    }
    if (max_uid_for_loop > 0 && uid_luid[0] == 0) {
        uid_luid[0] = 0;
    }
}
