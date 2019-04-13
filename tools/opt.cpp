#include <bits/stdc++.h>
using namespace std;

int n, m;
int find_ans;
vector < int > seq;
vector < int > alloc_id;
vector < int > seq_id;
vector < int > cur_method;
vector < bool > used;

void dfs (int now);

int main ()
{
	cin >> n;
	seq.resize ( 2*n+1 );
	alloc_id.resize ( 2*n+1 );
	seq_id.resize ( n+1 );
	cur_method.resize ( n+1 );
	int alloc_id_count = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> seq[i];
		if (seq[i] > 0) {
			++alloc_id_count;
			alloc_id[i] = alloc_id_count;
			seq_id[alloc_id_count] = i;
		}
	}
	find_ans = 0;
	for (int ans = 1; ; ++ans) {
		cout << "Checking answer = " << ans << endl;
		used.clear ();
		used.resize (ans+1, false);
		m = ans;
		dfs (1);
		if (find_ans) {
			cout << "Answer = " << ans << ", Find " << find_ans << " answer(s)" << endl;
			break;
		}
	}
}



void dfs (int now)
{
	if (now > 2*n) {
		++find_ans;
		cout << "Find answer #" << find_ans << ":" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << i << ": [" << cur_method[i] << "," << cur_method[i] + seq[seq_id[i]] - 1 << "]" << endl;
		}
		return;
	}
	if (seq[now] > 0) {
		for (int l = 1; l <= m - seq[now] + 1; ++l) {
			int r = l + seq[now] - 1;
			if (now == 1 && l > m - r + 1) {
				break;
			}
			bool ok = true;
			for (int i = l; i <= r; ++i) {
				if (used[i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int i = l; i <= r; ++i) {
					used[i] = true;
				}
				cur_method[alloc_id[now]] = l;
				dfs (now + 1);
				for (int i = l; i <= r; ++i) {
					used[i] = false;
				}
			}
		}
	} else {
		int l = cur_method[-seq[now]], r = l + seq[seq_id[-seq[now]]] - 1;
		for (int i = l; i <= r; ++i) {
			used[i] = false;
		}
		dfs (now + 1);
		for (int i = l; i <= r; ++i) {
			used[i] = true;
		}
	}
}
