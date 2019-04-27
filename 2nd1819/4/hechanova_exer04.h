int perfect(int N, int d)
{
	// base case where N is the only factor left
	if (d==N)
	{
		return 0;
	}

	// if factor, keep value
	else if (N%d==0)
	{
		return d + perfect(N, d+1);
	}

	// else, skip over
	return perfect(N, d+1);
}