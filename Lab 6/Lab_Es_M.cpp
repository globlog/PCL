#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

int main() {
	long long unsigned int x,n,count = 0,current_rating = 0;
	std::cin >> n;
	std::vector<long long unsigned int> ratings(n);
	
	for (long long unsigned int i = 0;i<n;++i){
		std::cin >> x;
		ratings[i]=x;
	}
	std::sort(ratings.begin(), ratings.end());
	for (long long unsigned int i = 0;i<n;++i){
		if(ratings[i]+i<=n){
			current_rating = ratings[i];
		} else {
			//std::cout << current_rating << " "<< ratings[i] << " " << n-i << " " << std::endl;
			current_rating = std::max(current_rating,n-i);
			break;
		}
	}
	std::cout << current_rating << std::endl;
	return 0;
}