#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

vector<string> split(const string& s, const int& para_size){
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	string para;
	int currentpara = 0;

	while (i != s.size()){
		while (isspace(s[i])){
			++i;
		}

		string_size j = i;
		while (j != s.size() && !isspace(s[j])){
			++j;
		}

		if (i != j){
			int wordsize = j-i;
			if ((currentpara+wordsize+1) <= para_size){
				currentpara = currentpara + wordsize + 1;
				para = para + s.substr(i, j - i) + " ";
				i = j;
			} else if (wordsize > para_size){
				i = j;
			} else {
				ret.push_back(para);
				currentpara = 0;
				para = "";
			}

			if (i == s.size()){
				ret.push_back(para);
			}
		}
	}
	return ret;
}

int frame(const string& s){
	int box_size = 30;
	int border_size = 1;
	int star_size = 1;
	int para_size = box_size - (border_size * 2) - (star_size * 2);

		for (int n = 0; n != star_size; ++n){
			for (int n = 0; n != box_size; ++n){
				cout << "*";
			}
			cout << endl;
		}

		for (int n = 0; n != border_size; ++n){
			for (int n = 0; n != box_size; ++n){
				if (n < star_size || n > (box_size-star_size-1)){
					cout << "*";
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}

		vector<string> words = split(s, para_size);

		for (vector<string>::size_type i = 0; i != words.size(); ++i){
			for (int n = 0; n != star_size; ++n){
				cout << "*";
			}

			for (int n = 0; n != border_size; ++n){
				cout << " ";
			}
		
			vector<string>::size_type wordsize = words[i].size();
			int addspaces = box_size - wordsize - (star_size*2) - (border_size*2);

			cout << words[i];

			for (int n = 0; n != addspaces; ++n){
				cout << " ";
			}

			for (int n = 0; n != border_size; ++n){
				cout << " ";
			}

			for (int n = 0; n != star_size; ++n){
				cout << "*";
			}
			cout << endl;
		}

		for (int n = 0; n != border_size; ++n){
			for (int n = 0; n != box_size; ++n){
				if (n < star_size || n > (box_size-star_size-1)){
					cout << "*";
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}

		for (int n = 0; n != star_size; ++n){
			for (int n = 0; n != box_size; ++n){
				cout << "*";
			}
			cout << endl;
		}
	return 0;
}

int main(){
	string p;

	cout << "Enter Paragraph: " << endl;

	while(getline(cin,p)){
		cout << endl;
		frame(p);
		cout << "Enter Paragraph: ";
	}
	return 0;
}