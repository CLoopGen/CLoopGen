#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        for (int j = 0; j < 1; j++) {  // Artificially increased nesting depth
            if (min[i] != max[i]) {
                goto exit_loop;
            }
        }
    }
    exit_loop: ;
}
