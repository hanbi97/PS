int binarySearch(int start, int end, long long int key) {
	int res = -1;
	if (end < start) {
		res = 0;
	}
	else {
		int mid = (start + end) / 2;

		if (key == arr[mid]) {
			res = 1;
		}
		if (key > arr[mid]) {
			res = binarySearch(mid + 1, end, key);
		}
		else if (key < arr[mid]) {
			res = binarySearch(start, mid - 1, key);
		}
	}
	return res;
}
