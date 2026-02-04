#include <stdio.h>

#include <inttypes.h>

extern size_t *len;
extern size_t i;
extern  uint8_t *ptr;
extern int found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_i;
    int match_occurred = 0;
    uint8_t* read_ptr = ptr;
    for (temp_i = 0; temp_i < *len && !match_occurred; ++temp_i) {
        if (*(read_ptr + temp_i) == 255 && 
            (temp_i + 1 < *len && *(read_ptr + temp_i + 1) == 255)) {
            match_occurred = 1;
        }
    }
    if (match_occurred) {
        ptr += temp_i;
        found = 1;
    } else {
        ptr += *len;
        found = 0;
    }
}
