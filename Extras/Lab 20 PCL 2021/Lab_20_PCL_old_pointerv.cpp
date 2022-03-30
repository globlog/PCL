#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <bits/stdc++.h>
using namespace std;

struct linked_word {
	std::string word;
	linked_word * next = NULL;
};

int main(){
	int N = 0;
	std::cin >> N;
	std::vector<linked_word * > words;
	std::string testo;
	for (int i = 0;i<N;++i){
		std::cin >> testo;
		linked_word * parola = new linked_word();
		parola->word = testo;
		words.push_back(parola);

	}
	//std::cout << "iniz";
	int x,y;
	linked_word * next_word = new linked_word();
	for (int j=0;j<N-1;++j){
		std::cin >> x >> y;
		next_word = words[x]->next;
		while (next_word != NULL){
		next_word = next_word->next;
		}
		next_word->next = words[y];
	}
	linked_word * current_word;
	current_word = words[x];
	for(int k = 0; k<N;++k){
		std::cout << (current_word->word) << endl;
		current_word = current_word->next;
	}

	
	return 0;

}