#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedStatistic,
    GradientStatistic,
    MaximumStatistic,
    MeanStatistic,
    MedianStatistic,
    MinimumStatistic,
    ModeStatistic,
    NonpeakStatistic,
    RootMeanSquareStatistic,
    StandardDeviationStatistic,
    ContrastStatistic
} StatisticType;

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

StatisticType type = MaximumStatistic;
ChannelStatistics *channel_statistics = NULL;
ssize_t i = 0;

void init_vars() {
    const size_t data_size = 65;
    channel_statistics = (ChannelStatistics*)calloc(data_size, sizeof(ChannelStatistics));
    if (!channel_statistics) {
        exit(1);
    }
    type = MaximumStatistic;
    i = 0;
}