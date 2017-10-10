template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector <edge> edges;
  vector < vector <int> > g;
  int n;
  graph(int n) : n(n) {
    g.resize(n);
  }
  virtual void add(int from, int to, T cost) = 0;
};
