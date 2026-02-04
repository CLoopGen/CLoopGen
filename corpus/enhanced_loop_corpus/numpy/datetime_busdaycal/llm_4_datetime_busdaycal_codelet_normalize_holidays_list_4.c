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
for (i = 0; i < count; ++i) {
    npy_datetime date = dates[i];
    if (date == (-(9223372036854775807LL) - (1LL)) || date == lastdate) {
        continue;
    }
    day_of_week = (int)((date - 4) % 7);
    if (day_of_week < 0) {
        day_of_week += 7;
    }
    if (weekmask[day_of_week]) {
        dates[trimcount++] = date;
        lastdate = date;
    }
}
}
