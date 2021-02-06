//최대값
int ps(int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) low = mid + 1;
		else high = mid - 1;
	}
	return low - 1;
}

//최소값
int ps(int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) high = mid - 1;
		else low = mid + 1;
	}
	return high + 1;
}