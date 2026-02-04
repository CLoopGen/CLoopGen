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
for (i = 0; i <= (ssize_t)64; i += 2) {
    ChannelStatistics *cs1 = channel_statistics + i;
    cs1->area = 0.;
    cs1->depth = 1;
    cs1->maxima = (-1.7976931348623157E+308);
    cs1->minima = 1.7976931348623157E+308;
    cs1->sum = 0.;
    cs1->sumLD = 0.;
    cs1->mean = 0.;
    cs1->standard_deviation = 0.;
    cs1->variance = 0.;
    cs1->skewness = 0.;
    cs1->kurtosis = 0.;
    cs1->entropy = 0.;

    if (i + 1 <= 64) {
        ChannelStatistics *cs2 = channel_statistics + i + 1;
        cs2->area = 0.;
        cs2->depth = 1;
        cs2->maxima = (-1.7976931348623157E+308);
        cs2->minima = 1.7976931348623157E+308;
        cs2->sum = 0.;
        cs2->sumLD = 0.;
        cs2->mean = 0.;
        cs2->standard_deviation = 0.;
        cs2->variance = 0.;
        cs2->skewness = 0.;
        cs2->kurtosis = 0.;
        cs2->entropy = 0.;
    }
}
}
