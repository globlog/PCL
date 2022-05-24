#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

std::pair<unsigned int,unsigned int> float_to_frac(std::string str){
	std::size_t found = str.find(".");
	unsigned int n,d;
	if (found < str.length()-1){
		n = std::stoi(str.substr(0,found));
		unsigned int v = std::stoi(str.substr(found+1,str.length()-found-1));
		unsigned int pow = 1;
		for (int i = 0; i< str.length()-found-1;++i){
			pow*=10;
		}
		n= n*pow+v;
		d = pow;
	} else {
		n = std::stoi(str);
		d = 1;
	}
	return {n/std::__gcd(n,d),d/std::__gcd(n,d)};
}

long long unsigned int strange_mod(long long unsigned int h){
	std::string str = std::to_string(h);
	return  std::stoi(str.substr(1,str.length()))*10+std::stoi(str.substr(0,1));
}


int main(){
	std::string x;
	std::cin >> x;
	long long unsigned int a = float_to_frac(x).first;
	long long unsigned int b = float_to_frac(x).second;
	long long unsigned int y = b;
	bool found = true;
	while (y<10){
		if (y*a == y*b){
			std::cout << y << std::endl;
			found = false;
		}
		y+=b;
	}
	while (y<100000000LL){
		if (y*a == strange_mod(y)*b){
			std::cout << y << std::endl;
			found = false;
		}
		y+=b;
	}
	if (found) {
		std::cout << "No solution" << std::endl;
	}
	//for (long long unsigned int i = 1; i<100000000LL; ++ i ){

	//}
	return 0;
}