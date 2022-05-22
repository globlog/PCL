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

int main(){
	int n,d;
	//94->90
	//95->100
	std::cin >> n >> d;
	long unsigned int prices [n];
	for (int i =0;i<n;++i){
		std::cin >> prices[i];
	}
	
	long unsigned int best[n+2][d+2];
	best[0][0]=0LL;
	for (int i =1 ; i<n+1; ++i){
		for (int x = 0; x<d+1;++x){
			if (x!= 0) {
				best[i][x]= std::min(best[i-1][x] + prices[i-1],approx(best[i-1][x-1]+ prices[i-1])) ;
			}
			else {
				best[i][x] = best[i-1][x] + prices[i-1];
			}
			
		} //std::cout<< best[i][d] << std::endl;
		
	}
	std::cout << approx(best[n][d]) << std::endl;
	return 0;
}