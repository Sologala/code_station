
#ifndef __ALG_HIERARCHICAL_CLUSTER_H__
#define __ALG_HIERARCHICAL_CLUSTER_H__
#include "union_set.h"
#include <queue>
#include <unordered_map>
#include <vector>
namespace alg {
namespace hierarchicalClustering {

using Result = std::unordered_map<size_t, std::vector<size_t>>;

template <typename T, typename Comp>

Result hierarchicalClustering(std::vector<T> &data, Comp& cmp) {
  UnionSet us(data.size());
  for (int i = 0, sz = data.size(); i < sz; i++) {
    for (int j = i + 1; j < sz; j++) {
      if (cmp(data[i], data[j])) {
        us.merge(i, j);
      }
    }
  }
  Result res;
  for (int i = 0, sz = data.size(); i < sz; i++) {
    size_t id = us.find(i);
    res[id].push_back(i);
  }
  return res;
}

} // namespace hierarchicalClustering
} // namespace alg

#endif
