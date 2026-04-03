void bucketSort(float arr[], int n) {
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i]; // index depends on value
        buckets[idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int k = 0;
    for (int i = 0; i < n; i++)
        for (float val : buckets[i])
            arr[k++] = val;
}
