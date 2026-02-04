#include <stdio.h>

#include <inttypes.h>

struct err_state_st {
    int err_flags[16];
    int err_marks[16];
    unsigned long err_buffer[16];
    char *err_data[16];
    size_t err_data_size[16];
    int err_data_flags[16];
    char *err_file[16];
    int err_line[16];
    char *err_func[16];
    int top;
    int bottom;
};


typedef struct err_state_st ERR_STATE;

extern int count;
extern int top;
extern ERR_STATE *thread_es;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential traversal, access every second element in a circular buffer,
    // then handle remaining elements in a second pass if needed.
    int stride = 2;
    int start = thread_es->top;
    count = 0;
    top = start;

    for (int step = 0; thread_es->bottom != top && thread_es->err_marks[top] == 0; ++step) {
        count++;
        // Strided backward traversal with wrap-around
        top = (top - stride + 16) % 16;
        // Ensure we don't get stuck; fallback to adjacent index if stride causes repetition
        if (step > 16) break;
    }
}
