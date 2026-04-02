#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    int n;
    vector<long long> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, long long val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n;
    cin >> n;
    BIT ft(n);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        ft.update(i, x);
    }
    cout << ft.query(1, n) << endl;
    return 0;
}
