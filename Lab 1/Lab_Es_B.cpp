#include <iostream>
#include <string>
#include <map>
#include <cctype>


int main() {
	std::map<std::string,char> lettere = {
	{"clank",'a'},
	{"bong",'b'},
	{"click",'c'},
	{"tap",'d'},
	{"poing",'e'},
	{"clonk",'f'},
	{"clack",'g'},
	{"ping",'h'},
	{"tip",'i'},
	{"cloing",'j'},
	{"tic",'k'},
	{"cling",'l'},
	{"bing",'m'},
	{"pong",'n'},
	{"clang",'o'},
	{"pang",'p'},
	{"clong",'q'},
	{"tac",'r'},
	{"boing",'s'},
	{"boink",'t'},
	{"cloink",'u'},
	{"rattle",'v'},
	{"clock",'w'},
	{"toc",'x'},
	{"clink",'y'},
	{"tuc",'z'},
	};
	std::string sentence;
	int nr_words;
	std::cin >> nr_words;
	
	bool caps = false;
	bool maj = false;
	bool ismaj;
	for (int j = 0 ; j < nr_words; j++){
	std::string x;
	std::cin >> x;
	if (x== "whack") {
		sentence.push_back(' ');
	} else if ( x == "pop"){
		sentence.pop_back();
	} else if ( x == "bump"){
		caps = not caps;
	} else if ( x == "dink"){
		maj = true;
	} else if ( x == "thumb"){
		maj = false;
	} else {
		ismaj = (caps != maj);
		if (not ismaj) {
		sentence.push_back(lettere[x]);
		} else {
		sentence.push_back(toupper(lettere[x]));
		}
	}
	}
	std::cout << sentence;
return 0;
}