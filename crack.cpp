#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
	string hash, salt, dict, true_hash, line, test_hash;
	cout << "Enter hash to break: ";
	cin >> hash;
	cout << "\nEnter dictionary to search: ";
	cin >> dict;
	
	salt = hash.substr(0, 2);
	true_hash = hash.substr(2, hash.length() - 2);
	ifstream fin(dict.c_str());
	
	cout << "\nThe salt: " << salt << endl;
	
	
	while(!fin.eof()) {
		getline(fin, line);
		test_hash = crypt(line.c_str(), salt.c_str());
		if (test_hash == hash) {
			cout << "The password is '" << line << "'." << endl;
			break;
		}
	}	
	
	return 0;
}
