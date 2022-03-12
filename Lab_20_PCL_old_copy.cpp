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
	linked_word parola1;
	parola1.word = "casa";
	std::cout << parola1.word << "1" << endl;
	linked_word * parola2;
	parola2 = &parola1;
	std::cout << parola2->word << "2" << "3" << endl;
	std::cout << (*parola2).word << "3" << endl;
	return 0;
}