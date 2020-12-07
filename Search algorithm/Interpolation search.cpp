int fun(int a[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (a[low] < key && a[high] >= key)
	{
		mid = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);
		if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	if (a[low] == key)
		return low;
	else
		return -1;
}


