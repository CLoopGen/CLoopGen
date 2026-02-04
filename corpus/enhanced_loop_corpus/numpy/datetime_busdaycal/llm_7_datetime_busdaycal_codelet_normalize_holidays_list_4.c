#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

typedef int npy_datetime;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_bool *weekmask;
extern npy_datetime *dates;
extern npy_intp count;
extern npy_datetime lastdate;
extern npy_intp trimcount;
extern npy_intp i;
extern int day_of_week;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_datetime temp_lastdate = lastdate;
    npy_intp temp_trimcount = trimcount;
    for (i = 0; i < count; ++i) {
        npy_datetime date = dates[i];
        if (date == (-(9223372036854775807LL) - (1LL)) || date == temp_lastdate) {
            continue;
        }
        int dow = (int)((date - 4) % 7);
        if (dow < 0) dow += 7;
        if (weekmask[dow]) {
            dates[temp_trimcount++] = date;
            temp_lastdate = date;
        }
    }
    trimcount = temp_trimcount;
    lastdate = temp_lastdate;
}
