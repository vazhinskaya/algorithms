int fun(int a[], int left, int right, int y) {
	if (left > right)
		return-1;
	int mid = (right + left) / 2;
	if (y = a[mid])
		return mid;
	if (y > mid)
		return fun(a, mid + 1, right, 3);
	else
		return fun(a, left, mid - 1, 3);
}