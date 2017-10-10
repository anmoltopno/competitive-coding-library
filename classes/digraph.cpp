template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  digraph(int n) : graph<T>(n) {
  }
  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    edges.push_back({from, to, cost});
  }
};
