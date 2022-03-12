#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <bits/stdc++.h>
using namespace std;

struct linked_word {
	std::string word;
	int next = -1;
	//int last = -1;
};

int main(){
	int N = 0;
	std::cin >> N;
	std::vector<linked_word> words ;
	linked_word parola;
	std::string testo;
	for (int i = 0;i<N;++i){
		std::cin >> testo;
		linked_word parola;
		parola.word = testo;
		//parola.last = i;
		words.push_back(parola);

	}
	//std::cout<< words[0].word << words[1].word << words[2].word << words[3].word;
	
	//std::cout << "iniz";
	int current_word;
	int x,y;
	for (int j=0;j<N-1;++j){
		std::cin >> x >> y;
		--x;
		--y;
		current_word = x;
		while (words[current_word].next !=-1){
			current_word = words[current_word].next;
		}
		words[current_word].next = y;
		//words[words[x].last].next = y;
		//words[x].last = words[y].last;
		//std::cout << words[x].next << " " << words[x].last; 
	}
	
	
	current_word = x;
	for(int k = 0; k<N;++k){
		std::cout << (words[current_word].word);
		current_word = words[current_word].next;
		//std::cout << current_word << endl;;
	}
	std::cout << endl;

	
	return 0;

}