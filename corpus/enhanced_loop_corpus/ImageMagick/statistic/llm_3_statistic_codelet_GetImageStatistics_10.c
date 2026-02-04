#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ChannelStatistics {
    size_t depth;
    double area;
    double minima;
    double maxima;
    double sum;
    double sum_squared;
    double sum_cubed;
    double sum_fourth_power;
    double mean;
    double variance;
    double standard_deviation;
    double kurtosis;
    double skewness;
    double entropy;
    double median;
    long double sumLD;
    long double M1;
    long double M2;
    long double M3;
    long double M4;
} ChannelStatistics;

extern ChannelStatistics *channel_statistics;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const ssize_t indices[] = {64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50,
                           49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35,
                           34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
                           19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5,
                           4, 3, 2, 1, 0};
for (ssize_t j = 0; j <= 64; j++) {
    ssize_t idx = indices[j];
    ChannelStatistics *cs = channel_statistics + idx;
    cs->area = 0.;
    cs->depth = 1;
    cs->maxima = (-1.7976931348623157E+308);
    cs->minima = 1.7976931348623157E+308;
    cs->sum = 0.;
    cs->sumLD = 0.;
    cs->mean = 0.;
    cs->standard_deviation = 0.;
    cs->variance = 0.;
    cs->skewness = 0.;
    cs->kurtosis = 0.;
    cs->entropy = 0.;
}
}
