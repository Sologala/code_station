#include "../hierarchical_clustering.h"
#include <random>
int main(int argc, char *argv[]) {
  const int N = 100;
  std::vector<int> data;
  for (int i = 0; i < N; i++) {
    int num = rand() % 100;
    data.push_back(num);
  }
  auto cmp = [](const int& a, const int&b){
    return abs(a - b) < 3;
  };
  auto res = alg::hierarchicalClustering::hierarchicalClustering<int, decltype(cmp)>(data,cmp);

  for(auto n : data){
    printf(" %d", n);      
  }
  printf("\n");
    for (auto p : res){
        printf("%d: ", p.first);
        for(auto i : p.second){
            printf("%d,", data[i]);
        }
        printf("\n");
    }
 return 0;
}
