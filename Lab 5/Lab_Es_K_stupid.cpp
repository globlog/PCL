#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>

int main() {
	long int nr_words, nr_tests;
	std::cin >> nr_words >> nr_tests;
	std::multiset <std::string> dictionary;
	std::string word,suffix;
	for(int w =0;w<nr_words;++w){
		std::cin >> word;
		dictionary.insert(word);
	}
	int word_len,suff_len;
	for(int t =0;t<nr_tests;++t){
		std::cin >> suffix;
		suff_len = suffix.size();
		for(std::multiset<std::string>::iterator it = dictionary.begin();it!=dictionary.end();++it){
			word= *it;
			word_len = word.size();
			if (word_len>=suff_len){
				if (word.compare(word_len-suff_len,suff_len,suffix) == 0){
					std::cout << word << std::endl;
				}
			}
		}
	}
	return 0;
}