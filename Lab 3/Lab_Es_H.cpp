#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

vector<long long unsigned int> fact = {1,1,2,6,24,120,720,5040,40320,362880,3628800};

long long unsigned int factorial(unsigned int n){
	return fact[n];
}

//vector<int> increasing_perms(int m){
	
//}

long long unsigned int combinations(vector<unsigned int> combi){
	long long unsigned int x = 1LL;
	long long unsigned int count = 0;
	for(int i = 1;i<11;i++){
		x*=factorial(combi[i]);
		count+=1;
	}
	return factorial(count)/x;
}

long long unsigned int total_alive = 0;


int main() {
	int k,m,n;
	std::cin >> k >> m >> n;
	std::cout << factorial(10);
	return 0;
}