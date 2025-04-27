#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

ifstream fin("input.txt");

using stringIntPair = std::pair<std::string, int>;
string input = "";
vector<string> words;

struct cmp {
	bool operator()(const stringIntPair& a, const stringIntPair& b) const {
		if (a.second == b.second) {
			int i;
			for (i = 0; a.first[i] != '\0' && b.first[i] != '\0'; i++)
				if(a.first[i] != b.first[i])
					return a.first[i] > b.first[i];
			if (a.first[i] == '\0')
				return 0;
			return 1;
		}
		return a.second < b.second;
	}
};

priority_queue<stringIntPair, vector<stringIntPair>, cmp> Q;
map<string, int> M;

bool is_separator(char a) {
	return (a == ' ' || a == ',' || a == '.' || a == '!' || a == '?');
}

void to_lower(string& a) {
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
}

vector<string> split_into_words(string phrase) {
	string curr_word = "";
	vector<string> w;
	for (int i = 0; phrase[i] != '\0'; i = i) {
		curr_word.clear();
		for (;is_separator(phrase[i]); i ++);
		for (; phrase[i] != '\0' && !is_separator(phrase[i]); i ++)
			curr_word += phrase[i];
		to_lower(curr_word);
		if (!curr_word.empty()) {
			if(M[curr_word] == 0)
				w.push_back(curr_word);
			M[curr_word]++;
		}
	}
	return w;
}

void process_map() {
	for (auto& p : M) 
		Q.push(make_pair(p.first, p.second));
	while (!Q.empty()) {
		cout << Q.top().first << " => " << Q.top().second << '\n';
		Q.pop(); 
	}
}

int main() {
	getline(fin, input);
	words = split_into_words(input);
	process_map();
}