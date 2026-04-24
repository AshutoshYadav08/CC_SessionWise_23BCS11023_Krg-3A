#include <vector>

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int i, T val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }

    T query(int i) {
        T sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
