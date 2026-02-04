#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern int x_end;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = *y_start; i < y_end; i++) {
        size_t index1 = linesize * i + x_end;
        size_t index2 = linesize * i + x_end - 1;
        size_t index3 = linesize * i + x_end + 1;
        // Perform additional boundary checks with increased computational load
        if (x_end > 0 && buf[index2] == trans &&
            buf[index1] != trans &&
            x_end < linesize - 1 && buf[index3] == trans) {
            is_trans = 0;
            break;
        }
        // Additional redundant computation to increase arithmetic operations
        volatile int dummy = (index1 * index2) % (index3 + 1);
        (void)dummy;
    }
}
