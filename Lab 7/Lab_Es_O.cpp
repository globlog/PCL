#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

int main() {
	int N,k;
	long unsigned int l,r;
	std::cin >> N >> k;
	while (N!=0 || k!=0){
	std::vector<std::pair<long unsigned int,long unsigned int>> gallery(N);
	for(int i = 0 ;i<N;++i){
		std::cin >> l >> r;
		gallery[i]={l,r};
	}
	std::vector<std::pair<long unsigned int,long unsigned int>> zeroses(k+2,{0,0});	
	std::vector<std::pair<long unsigned int,long unsigned int>> current_emptied(k+2,{0,0});
	std::vector<std::pair<long unsigned int,long unsigned int>> next_emptied(k+2,{0,0});
	long unsigned int l1,l2,r1,r2;
	for(int i = 0 ;i<N;++i){
		next_emptied[0].first=current_emptied[0].second+gallery[i].second+gallery[i].first;
		next_emptied[0].second=current_emptied[0].first+gallery[i].second+gallery[i].first;
		for(int j=0;j<i && j<=k;++j){
			l1 = current_emptied[j].first;
			r1 = current_emptied[j].second;
			l2 = current_emptied[j+1].first;
			r2 = current_emptied[j+1].second;
			long unsigned int gal = std::max(l2,r2)+(gallery[i].first+gallery[i].second);
			next_emptied[j+1].first=std::max(l1+gallery[i].first,gal);
			next_emptied[j+1].second=std::max(r1+gallery[i].second,gal);
		}
		if (i<=k){
		next_emptied[i+1].first=current_emptied[i].first+gallery[i].first;
		next_emptied[i+1].second=current_emptied[i].second+gallery[i].second;
		}
		current_emptied = next_emptied;
		next_emptied = zeroses;
	}
	std::cout << std::max(current_emptied[k].first,current_emptied[k].second) << std::endl;
	std::cin >> N >> k;
	}
	return 0;
}