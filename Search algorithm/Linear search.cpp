int fun(int *a, int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
			return i;
	}
	return -1;
}
