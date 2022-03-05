#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int chil(std::vector<long long int> A, std::vector<long long int> B , long long int p , long long int q) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long int chilometri_visti = 0;
	long long int pos, set_start;
	long long unsigned int current_alive = 0;	


	while (A.empty()==0){
			if (*A.begin() < *B.begin() ){
				current_alive+=1;
				if (current_alive == 1){
					set_start = *A.begin();
				}
				A.erase(A.begin());
			} else if (*A.begin() > *B.begin() ){
				current_alive-=1;
				if (current_alive == 0){
					chilometri_visti += std::max(std::min(*B.begin(),q)-std::max(set_start,p),0LL);
				}
				B.erase(B.begin());
			} else {
				A.erase(A.begin());
				B.erase(B.begin());
			}
		}
			while (B.empty()==0){
			current_alive-=1;
			if (current_alive == 0){
				chilometri_visti += std::max(std::min(*B.begin(),q)-std::max(set_start,p),0LL);
			}
			B.erase(B.begin());
		}	
		
	//std::cout << chilometri_visti;
	return q-p - (chilometri_visti);
}

int main(){
	std::vector<long long int> X{-1,2,9};
	std::vector<long long int> Y{5,3,12};
	long long int p = 0;
	long long int q = 10;
	std::cout << chil(X,Y,p,q) << endl;
	return 0;
}