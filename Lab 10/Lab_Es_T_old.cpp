#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

long unsigned int approx(const long unsigned int & u){
	if ((u/5)%2==0) {
		return u-(u%5);
	} else {
		return u+5-(u%5);
	}
}

std::pair<long unsigned int,long unsigned int> next_best(std::vector<std::pair<long unsigned int,long unsigned int>> current_pairs,long unsigned int summand){
	long unsigned int best = current_pairs[0].first+approx(current_pairs[0].second+summand);
	for (long unsigned int i = 0;i< current_pairs.size();++i){
		best = std::min(best,current_pairs[i].first+approx(current_pairs[i].second+summand));
	}
	//std::cout << best << std::endl;
	return {best,0LL};


}


int main(){
	int n,d;
	//94->90
	//95->100
	std::cin >> n >> d;
	long unsigned int prices [n];
	for (int i =0;i<n;++i){
		std::cin >> prices[i];
	}
	d = min(d,n-1);
	std::vector<std::pair<long unsigned int,long unsigned int>> best[n+1][d+2];
	best[0][0].push_back({0,0});
	for (int i =1 ; i<n+1; ++i){
			for (int x = 0; x<d+1 && x<=i;++x){
				for (int j = 0;j<best[i-1][x].size();++j){
					best[i][x].push_back({best[i-1][x][j].first,best[i-1][x][j].second+prices[i-1]});
					best[i][x+1].push_back(next_best(best[i-1][x],prices[i-1]));
			}
		}
	}
	std::cout << (next_best(best[n][d+1],0)).first << std::endl;
	return 0;
}