int try(vector<int> a) {
	if (a.size() <= 1) return  a.size();
	vector<int> result(a.size(), 1);
	for (int i = 1; i < a.size(); i++) {
		int prev = i-1;
		int prev_prev = i-1-1;
		if (prev_prev >= 0) {
			if ((A[i] < A[prev] && A[prev] > A[prev_prev])
				   	|| (A[i] > A[prev] && A[prev] < A[prev_prev])) {
				result[i] = result[prev]+1;
			} else {
				if (A[i] != A[prev]) {
					result[i] = 2;
				}
			}
		} else {
			if (A[i] != A[prev]) {
				result[i] = 2;
			}
		}
	}
	return max(result);
}
