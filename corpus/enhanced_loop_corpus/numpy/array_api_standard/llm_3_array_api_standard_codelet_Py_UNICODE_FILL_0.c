#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef wchar_t Py_UNICODE;

typedef ssize_t Py_ssize_t;

extern Py_UNICODE *target;
extern Py_UNICODE value;
extern Py_ssize_t length;
extern Py_ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via alternating forward and backward indices)
    // Simulates non-sequential access pattern without additional data structures
    Py_ssize_t left = 0;
    Py_ssize_t right = length - 1;
    while (left <= right) {
        target[left] = value;
        if (left != right) {
            target[right] = value;
        }
        left++;
        right--;
    }
}
