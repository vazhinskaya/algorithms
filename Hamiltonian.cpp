int fun(int k)
{
	int v, b = 0;
	for (v = 0; v < n && !b; v++)
	{
		if (a[v][path[k - 1]] || a[path[k - 1]][v])
		{
			if (k == n && v == v0) b = 1;
			else if (c[v] == -1)
			{
				c[v] = k; path[k] = v;
				b = fun (k + 1);
				if (!b) c[v] = -1;
			}
			else continue;
		}
	} return b;
}