#include <iostream>
#include <vector>
#include <functional>

/**
 * @class SegmentTree
 * @brief A class that implements a Segment Tree for efficient range queries and point updates.
 *
 * This implementation is templated to allow for different data types and is
 * configured for range sum queries by default, but can be adapted for other
 * associative operations like min, max, etc.
 *
 * @tparam T The data type of the elements in the array.
 */
template <typename T>
class SegmentTree {
public:
    /**
     * @brief Constructs a Segment Tree from a given array of data.
     * @param data The input data (std::vector) to build the tree from.
     */
    explicit SegmentTree(const std::vector<T>& data) {
        n = data.size();
        // The size of the tree can be up to 4n to be safe
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    /**
     * @brief Performs a range query on the segment tree.
     * @param left The starting index of the query range (inclusive).
     * @param right The ending index of the query range (inclusive).
     * @return The result of the operation over the given range.
     */
    T query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    /**
     * @brief Updates an element at a specific index and propagates the change up the tree.
     * @param index The index of the element to update.
     * @param newValue The new value for the element at the given index.
     */
    void update(int index, T newValue) {
        update(1, 0, n - 1, index, newValue);
    }

private:
    std::vector<T> tree;
    int n;

    T merge(T a, T b) {
        return a + b;
    }


    void build(const std::vector<T>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = start + (end - start) / 2;
            // Recurse on the left child
            build(data, 2 * node, start, mid);
            // Recurse on the right child
            build(data, 2 * node + 1, mid + 1, end);
            // Internal node: merge the results from children
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    /**
     * @brief Recursive helper for updating a value.
     * @param node Current node index.
     * @param start Start of the node's range.
     * @param end End of the node's range.
     * @param idx The index in the original array to update.
     * @param val The new value.
     */
    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            // Leaf node: update the value
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            if (start <= idx && idx <= mid) {
                // If index is in the left child, recurse on the left child
                update(2 * node, start, mid, idx, val);
            } else {
                // If index is in the right child, recurse on the right child
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            // Update the internal node by merging children
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }


     query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; 
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return merge(p1, p2);
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};

    SegmentTree<int> st(data);

    std::cout << "Sum of range [1, 3]: " << st.query(1, 3) << std::endl;

    st.update(2, 6);
    data[2] = 6; 

    std::cout << "After updating index 2 to 6," << std::endl;
    std::cout << "Sum of range [1, 3]: " << st.query(1, 3) << std::endl;
    
    std::cout << "Sum of range [0, 5]: " << st.query(0, 5) << std::endl;

    return 0;
}
