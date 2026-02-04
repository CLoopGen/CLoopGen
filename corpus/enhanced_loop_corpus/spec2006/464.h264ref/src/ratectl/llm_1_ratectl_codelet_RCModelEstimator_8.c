#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean m_rgRejected[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop_count = (n_windowSize + 255) / 256;
    for (i = 0; i < outer_loop_count; i++) {
        int start = i * 256;
        int end = (start + 256 < n_windowSize) ? start + 256 : n_windowSize;
        for (int k = start; k < end; k++) {
            if (m_rgRejected[k])
                n_realSize--;
        }
    }
}
