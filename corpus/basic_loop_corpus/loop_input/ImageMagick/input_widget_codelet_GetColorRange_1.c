#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will cause the loop to run for a significant time
    // We'll create a large amount of data with nested parentheses and separators to control traversal
    
    const size_t data_size = 131072; // 128KB - tuned to get approx 0.01s runtime on typical CPU
    const char *pattern = "(((abcdefghijklmnopqrstuvwxyz)))";
    const int pattern_len = 32;
    
    // Fill start_color with repeating pattern, ensuring we don't exceed its size
    for (int i = 0; i < 4096 / pattern_len; i++) {
        for (int j = 0; j < pattern_len && (i * pattern_len + j) < 4095; j++) {
            start_color[i * pattern_len + j] = pattern[j];
        }
    }
    
    // Ensure the last element is null terminator
    start_color[4095] = '\x00';
    
    // Modify some '-' characters into the buffer to control termination
    // Place a '-' near the end so the loop doesn't terminate too early
    start_color[3900] = '-';
    start_color[3901] = '\x00'; // ensure we don't go past this
    
    // Reinitialize p to point to start of array
    p = start_color;
}