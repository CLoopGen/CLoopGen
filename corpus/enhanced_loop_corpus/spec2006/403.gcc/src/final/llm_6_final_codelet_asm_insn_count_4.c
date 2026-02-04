#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_count = count;
    const char *tmp_ptr = template;
    for (; *tmp_ptr; tmp_ptr++) {
        if ((*tmp_ptr == ';') || (*tmp_ptr == '\n')) {
            temp_count++;
        }
    }
    count = temp_count;
}
