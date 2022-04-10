#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

int max_common_length(std::string prefix, std::string word){
	int len = 0;
	int prefix_len = prefix.size();
	for(int i = 0; i!=prefix_len+1; i++){
		len = prefix_len-i;
		if (prefix.substr(i,prefix_len)==word.substr(0,len)){
			break;
		}
	}
	return len;
}


std::vector<std::pair<int,int>> substring_matcher(std::string word){
 	std::vector<std::pair<int,int>> matches;
	std::pair<int,int> zero_one;
	std::string add_zero,add_one;
 	for(int i = 0; i!=word.size(); i++){
		add_zero = word.substr(0,i)+'0';
		add_one = word.substr(0,i)+'1';
		matches.push_back({max_common_length(add_zero,word),max_common_length(add_one,word)});
	}
	return matches;
 }


int main() {
	long long unsigned int modulus = 1000000007LL;
	int T,w_len;
	std::string word;
	std::cin >> T;
	for(int k = 0;k<T; ++k){
		std::cin >> w_len >> word;
		std::vector<std::pair<int,int>> matches = substring_matcher(word);
		// for(int i = 0;i!=matches.size();i++){
		// 	std::cout << matches[i].first << " " << matches[i].second << std::endl;
		// }
		// std::cout << std::endl;
		int n = word.size();
		
		std::vector<std::vector<long long unsigned int>> multifib (w_len+1,std::vector<long long unsigned int> (n+1,0));
		multifib[0][0] = 1;
		for (int i=1;i<w_len+1;++i){
			for(int j=0;j<n;++j){
				multifib[i][matches[j].first] = (multifib[i][matches[j].first]+multifib[i-1][j]) % modulus;
				multifib[i][matches[j].second] = (multifib[i][matches[j].second]+multifib[i-1][j]) % modulus;
			}
		}
		long long unsigned int results = 0LL;
		for(int j=0;j<n;++j){
			results = (results + multifib[w_len][j]) % modulus;
		}
		std::cout << results << std::endl;
		
		//long long unsigned int sum_of_elems = std::accumulate(multifib[i].begin(), multifib[i].end(), 0); 
		//std::cout << sum_of_elems << std::endl;
		
	}
	return 0;
}