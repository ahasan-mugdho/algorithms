void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) maxVal = max(maxVal, arr[i]);

    vector<int> count(maxVal + 1);

    for (int i = 0; i < n; i++) count[arr[i]]++;
  
    int j=0;
    for (int i = 0;i<=maxVal;i++) {
        while(count[i]>0)
        {
          arr[j]=i;
          count[i]--;
          j++;
        }
    }

   
}
