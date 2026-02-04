#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will make the loop run for significant time
    // We'll create a large buffer with nested parentheses and separators to force deep scanning
    const size_t total_size = 128 * 1024 * 1024; // 128MB data to ensure ~0.01s runtime on modern CPU
    static char* big_buffer = NULL;
    
    if (big_buffer == NULL) {
        big_buffer = (char*)malloc(total_size);
        if (!big_buffer) exit(1);
        
        size_t pos = 0;
        // Create repeating patterns of: abc(defg)hij-
        const char* pattern = "abc(defg)hij";
        const int pat_len = 11;
        const int cycle_len = pat_len; // no dash yet
        
        while (pos + cycle_len + 1 < total_size) {
            memcpy(big_buffer + pos, pattern, pat_len);
            pos += cycle_len;
            // Every 100th group ends with '-' to eventually terminate outer loop
            if ((pos / cycle_len) % 100 == 0) {
                big_buffer[pos++] = '-';
            } else {
                big_buffer[pos++] = 'k'; // continue chain
            }
        }
        // Ensure null termination at the end
        if (pos < total_size - 1) {
            memset(big_buffer + pos, 'x', total_size - pos - 1);
            big_buffer[total_size - 1] = '\0';
        } else {
            big_buffer[total_size - 1] = '\0';
        }
        
        // Set up start_color as a window into this large buffer
        memcpy(start_color, "xyz(abc", 7);
        // Make sure initial p doesn't point to null or dash immediately
    }
    
    // Copy relevant portion to start_color for direct access
    memcpy(start_color, "a(bcd)ef-", 9);
    
    // Reinitialize p to point to start of start_color
    p = start_color;
}