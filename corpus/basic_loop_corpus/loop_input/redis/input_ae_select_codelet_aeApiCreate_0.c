#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/select.h>

typedef long __fd_mask;

unsigned int __i;
fd_set *__arr;

void init_vars() {
    static fd_set arr_instance;
    __arr = &arr_instance;

    for (size_t i = 0; i < sizeof(fd_set) / sizeof(__fd_mask); ++i) {
        ((__arr)->__fds_bits)[i] = 0;
    }
}