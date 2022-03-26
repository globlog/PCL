#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>

int main() {
	std::vector<long long int> fibonacci(10002);
	fibonacci[0]=1LL;
	fibonacci[1]=2LL;
	for (int i=2;i<10002;++i){
		fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2]) % 1000000007LL ;
	}
	unsigned int n;
	std::cin >> n;
	unsigned int l;
	for (int j=0;j<n;++j){
		std::cin >> l;
		std::cout << fibonacci[l] << std::endl;
	}
	return 0;
}