#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int seq_no;
extern char marker_present[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (seq_no = 0; seq_no < 256; seq_no += 2) {
        marker_present[seq_no] = 0;
        if (seq_no + 1 < 256) {
            marker_present[seq_no + 1] = 0;
        }
    }
}
