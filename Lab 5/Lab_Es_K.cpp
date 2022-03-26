// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Trie Node
struct Trie {
	Trie* arr[27] = { NULL };

	// Stores the index of the word
	// in the dictionary
	multiset<string> words;
};

// Root node of the Trie
Trie* root = new Trie();

// Function to insert the words in
// the Trie
void insert(string word)
{
	// Temporary pointer to the root
	// node of the Trie
	Trie* temp = root;

    string reverse_word = word;
    reverse(reverse_word.begin(),reverse_word.end());
	// Traverse through all the
	// characters of current word
	for (char ch : reverse_word ) {

		// Make a Trie Node, if not
		// already present
		if (temp->arr[ch - 'a'] == NULL) {
			Trie* t = new Trie();
			temp->arr[ch - 'a'] = t;
		}

		temp = temp->arr[ch - 'a'];
		(temp->words).insert(word);
	}
}

// Function to search the words in Trie
Trie* search(string word)
{
	Trie* temp = root;

	// Traverse through all the
	// characters of current word
    string reverse_word = word;
    reverse(reverse_word.begin(),reverse_word.end());
	for (char ch : reverse_word) {

		// If no valid Trie Node exists
		// for the current character
		// then there is no match
		if (temp->arr[ch - 'a'] == NULL)
			return NULL;
		temp = temp->arr[ch - 'a'];
	}

	// Return the resultant index
	return temp;
}

// Function to search for a word in
// the dictionary with the given
// prefix and suffix for each query

// Driver Code

int main() {
	long int nr_words, nr_tests;
	std::cin >> nr_words >> nr_tests;
	std::string word,suffix;
	for(int w =0;w<nr_words;++w){
		std::cin >> word;
		insert(word);
	}

	for(int t =0;t<nr_tests;++t){
		std::cin >> suffix;
        Trie * startnode = search(suffix);
        if (startnode!=NULL){
            for (multiset<string>::iterator it = (startnode->words).begin();it!=(startnode->words).end();it++){
                std::cout << *it <<std::endl;
            }
        }
    }
    return 0;
}