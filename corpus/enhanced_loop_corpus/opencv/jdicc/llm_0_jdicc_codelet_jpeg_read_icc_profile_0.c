#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int seq_no;
extern char marker_present[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (seq_no = 1; seq_no <= 255; seq_no++)
            marker_present[seq_no] = 0;
    }
}
