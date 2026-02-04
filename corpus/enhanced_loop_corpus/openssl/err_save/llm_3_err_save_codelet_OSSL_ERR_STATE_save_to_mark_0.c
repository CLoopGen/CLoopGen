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
    // Variant 2: Indirect Access via Index Remapping
    // Use an auxiliary array to define the access order (indirection),
    // simulating non-linear or reordered traversal of err_marks.
    static const int index_map[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}; // Bit-reversed order
    int mapped_index = -1;
    count = 0;
    top = thread_es->top;

    // Find the position of current top in the index map
    for (int i = 0; i < 16; ++i) {
        if (index_map[i] == top) {
            mapped_index = i;
            break;
        }
    }

    // Traverse using mapped indices in reverse order
    for (; mapped_index >= 0 && thread_es->bottom != top && thread_es->err_marks[top] == 0; --mapped_index) {
        count++;
        top = index_map[mapped_index];
    }
}
