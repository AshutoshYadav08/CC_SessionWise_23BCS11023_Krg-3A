#include <vector>
#include <cmath>
#include <algorithm>

template <typename T>
struct SparseTable {
    std::vector<std::vector<T>> st;
    std::vector<int> log_table;
    int n;

    SparseTable(const std::vector<T>& v) {
        n = v.size();
        if (n == 0) return;
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        st.resize(log_table[n] + 1, std::vector<T>(n));
        st[0] = v;

        for (int i = 1; i <= log_table[n]; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = log_table[r - l + 1];
        return std::min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};