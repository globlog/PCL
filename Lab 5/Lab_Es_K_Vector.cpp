#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


string nextWord(string s)
{
    // If string is empty.
    if (s == "")
        return "a";
 
    // Find first character from right
    // which is not z.
     
    int i = s.length() - 1;
    while (s[i] == 'z' && i >= 0)
        i--;
 
    // If all characters are 'z', append
    // an 'a' at the end.
    if (i == -1)
        s = s + 'a';
 
    // If there are some non-z characters
    else
        s[i]++;
 
    return s;
}

int binary_search(const std::string & key,const std::vector<std::string> & sorted_vect){
	int left = 0;
	int right = sorted_vect.size();
	while (left < right) {
      int mid = left + (right - left)/2;
      if (sorted_vect[mid] >= key ){
          right = mid-1;
      }
      else {
        left = mid+1;
      }                                                                                                               
   }
   int a = left;

//    left = 0;
//    right = sorted_vect.size();
//    while (left < right) {
//       int mid = left + (right - left)/2;
//       if (sorted_vect[mid] > key){
//           right = mid-1;
//       }
//       else{
//         left = mid+1;
//       }                                                                                                               
//    }
//    int b = left;
   return a;   
}


int main() {
	long int nr_words, nr_tests;
	std::cin >> nr_words >> nr_tests;
	std::string word,suffix;
	std::vector<std::string> reverse_dictionary(nr_words);
	for(int w =0;w<nr_words;++w){
		std::cin >> word;
		reverse(word.begin(),word.end());
		reverse_dictionary[w]=word;
	}
	std::sort(reverse_dictionary.begin(),reverse_dictionary.end());

	for(int t =0;t<nr_tests;++t){
		std::multiset<std::string> subdict;
		std::cin >> suffix;
		reverse(suffix.begin(),suffix.end());
        std::pair<int,int> start_end = {binary_search(suffix,reverse_dictionary),binary_search(nextWord(suffix),reverse_dictionary)};
		for(int i = std::get<0>(start_end) ;i< std::get<1>(start_end);++i){
			word = reverse_dictionary[i];
			reverse(word.begin(),word.end());
			subdict.insert(word);
		}
		for (std::multiset<std::string>::iterator it = subdict.begin();it!=subdict.end();++it){
			std:: cout << *it << endl;
		}
		

    
    }
    return 0;
}