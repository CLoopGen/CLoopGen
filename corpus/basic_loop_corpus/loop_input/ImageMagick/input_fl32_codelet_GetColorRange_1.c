#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color buffer with a pattern that will cause the loop to run for a measurable duration
    // We'll create a large data set with nested patterns to simulate realistic traversal
    
    size_t total_size = 1 << 20; // ~1MB of data to target ~0.01 sec runtime on modern CPU
    char *data = (char*)malloc(total_size);
    if (!data) {
        return;
    }

    size_t pos = 0;
    // Create repeating pattern: "abc(defg)hij-" to trigger both loops and conditional breaks
    const char *pattern1 = "abc(defg)hij";
    const char *pattern2 = "klm(no)pqr";
    const char *pattern3 = "stu(vwx)yzz";
    
    while (pos < total_size - 64) {
        // Interleave patterns with parentheses and non-parentheses sequences
        strcpy(&data[pos], pattern1);
        pos += strlen(pattern1);
        strcpy(&data[pos], pattern2);
        pos += strlen(pattern2);
        strcpy(&data[pos], pattern3);
        pos += strlen(pattern3);
        
        // Occasionally insert a '-' to prevent infinite looping, but far at the end
        if (pos > total_size - 128) {
            data[pos] = '-';
            pos++;
        }
    }
    
    // Ensure null termination near the end but after potential '-' character
    if (pos < total_size - 1) {
        data[pos] = '-';
        pos++;
    }
    if (pos < total_size) {
        data[pos] = '\0';
    } else {
        data[total_size-1] = '\0';
    }
    
    // Copy into start_color (4096-byte buffer), but ensure we don't overflow
    size_t copy_size = (total_size > sizeof(start_color)) ? sizeof(start_color) : total_size;
    memcpy(start_color, data, copy_size);
    start_color[sizeof(start_color)-1] = '\0'; // Guarantee null termination
    
    free(data);
    
    // Initialize p to start of array
    p = start_color;
}