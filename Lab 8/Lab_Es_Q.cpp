#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

int main() {
	int n;
	char n1,n2;
	int c1 = 0,c2 = 0;
	std::string w1,w2;
	std::cin >> n;
	std::cin >> w1;
	std::cin >> w2;
	n1 = w1[0];
	n2 = w2[0];
	for(int i =1;i<n;++i){
		if (w1[i]!=n1){
			n1=w1[i];
			c1+=1;
		}
		if (w2[i]!=n2){
			n2=w2[i];
			c2+=1;
		}
	}
	if (w1[n-1]!=w1[0]){
			c1+=1;
		}
	if (w2[n-1]!=w2[0]){
			c2+=1;
	}
	//std::cout << c1 << " "<< c2;
	if (c1>c2 || (c1==c2 && (c1!=n && c1!=0)) ){
		std::cout << "yes" << std::endl;
	} else {
		std::cout << "no" << std::endl;
	}

		return 0;
}