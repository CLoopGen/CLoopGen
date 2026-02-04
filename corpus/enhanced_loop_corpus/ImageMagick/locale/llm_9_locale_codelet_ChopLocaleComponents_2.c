#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *path;
extern  size_t components;
extern char *p;
extern ssize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    count = 0;
    const ptrdiff_t step = 3; // Process multiple characters per iteration to reduce total iterations
    ptrdiff_t distance = p - path;
    ptrdiff_t adjusted_count = (distance + step - 1) / step; // Approximate number of steps needed

    for (ptrdiff_t i = 0; i < adjusted_count && (p > path); i++) {
        // Perform multiple checks per loop iteration to increase arithmetic and memory operations
        for (int j = 0; j < step && (p > path); j++, p--) {
            if (*p == '/') {
                *p = '\x00';
                count++;
                if (count >= (ssize_t)components) goto exit_loop; // Exit early if component limit met
            }
        }
    }
exit_loop:;
}
