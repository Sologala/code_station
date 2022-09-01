#ifndef __ALG_UNION_SET_H__
#define __ALG_UNION_SET_H__

#include <vector>
namespace alg {

class UnionSet {
public:
  UnionSet(size_t size) { init(size); }
  ~UnionSet() = default;
  void init(size_t size) {
    fa.resize(size + 1);
    rank.resize(size + 1);
    for (size_t i = 1, sz = fa.size(); i < sz; ++i) {
      fa[i] = i;
      rank[i] = 1;
    }
  }
  int find(size_t i) { return i == fa[i] ? i : (fa[i] = find(fa[i])); }

  void merge(size_t i, size_t j) {
    if (i >= fa.size() || j >= fa.size()) {
      return;
    }
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
      fa[x] = y;
    else
      fa[y] = x;
    if (rank[x] == rank[y] && x != y)
      rank[y]++;
  }
  std::vector<size_t> fa;
  std::vector<size_t> rank;
};

} // namespace alg
#endif
