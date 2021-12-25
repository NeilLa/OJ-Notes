int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int times = 0;

    for (int i = 0; i < timeSeriesSize; i++) {
        int start = timeSeries[i];
        int end = start + duration;

        if (i < timeSeriesSize - 1) {
            if (end < timeSeries[i + 1]) {
                times = times + (end - start);
            } else {
                times = times + timeSeries[i + 1] - start;
            }
        } else {
            times = times + duration;
        }
    }

    return times;
}