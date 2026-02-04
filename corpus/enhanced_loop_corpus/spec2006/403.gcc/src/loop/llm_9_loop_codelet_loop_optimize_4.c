#include <stdio.h>

#include <inttypes.h>

extern int *uid_luid;
extern int max_uid_for_loop;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = 0; i < max_uid_for_loop; i++) {
        if ((i % (step + 1)) == 0) {
            if (uid_luid[i] == 0 && i > 0)
                uid_luid[i] = uid_luid[i - 1];
        } else {
            uid_luid[i] = uid_luid[i] * 2;
        }
    }
}
