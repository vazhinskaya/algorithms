void quickSort(int a[], int left, int right) {
	int i = left, j = right;
	int t;
	int pivot = a[(left + right) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	};

	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);

}