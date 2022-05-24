#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

std::pair<long long int,long long int> float_to_frac(std::string str){
	long long int n = 0;
	long long int d = 1;
	bool found = false;
	for (int i = 0; i < str.size(); i++) {
		if (found) {
			d*=10;
		}
		if (str[i] == '.'){
			found = true;
		} else {
			n*=10;
			n+= (str[i]-'0');
		}
	}
	
	return {n/std::__gcd(n,d),d/std::__gcd(n,d)};
}

int main(){
	std::string x;
	std::cin >> x;
	long long int a = float_to_frac(x).first;
	long long int b = float_to_frac(x).second;
	long long int y;
	bool found = true;
	long long int ten = 10LL;
	long long int p,q;
    for(long long int x = 1;x<=9;++x){
        if (x*a == x*b){
            std::cout << x << std::endl;
        }
    }
	for (long long int n = 1 ; n<8;++n){
		for(long long int x = 1;x<=9;++x){
			p = x*ten*a-x*b;
			q = 10*b-a;
			if (p!= 0 && q != 0){
				if (p%q == 0){
					y = p/q;
					if (y>0 && y < ten){
						std::cout << x << y << std::endl;
						found = false;
					}
				}
			}
			
		}

		ten *=10;
	}
	if (found) {
		std::cout << "No solution" << std::endl;
	}
	return 0;
}