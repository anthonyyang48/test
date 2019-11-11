#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

//Vector holding the input(s)
vector<string> input;

//Vector holding the duplicate(s)
vector<string> duplicate;

//Vector holding the unique(s)
vector<string> unique;

//Searches if a specific string is in a vector
bool find(vector<string> V, string c);

//Prints the number of occurences
void occurenceCount(vector<string> V);

//Prints duplicate line(s)
void duplicateLine(vector<string> V1, vector<string> V2);

// Prints unique line(s)
void uniqueLine(vector<string> V);

//Counts the number of duplicate line(s)
void countDuplicateLine(vector<string> V1, vector<string> V2);

//Counts the number of unique line(s)
void countUniqueLine(vector<string> V1, vector<string> V2);

//Prints each distinct value once
void distinct(vector<string> V1, vector<string> V2);

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";

int main(int argc, char *argv[]) {
	// define long options
	static int showcount=0, dupsonly=0, uniqonly=0;
	static struct option long_opts[] = {
		{"count",         no_argument, 0, 'c'},
		{"repeated",      no_argument, 0, 'd'},
		{"unique",        no_argument, 0, 'u'},
		{"help",          no_argument, 0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cduh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				showcount = 1;
				break;
			case 'd':
				dupsonly = 1;
				break;
			case 'u':
				uniqonly = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	/* TODO: write me... */

	string userInput;

	while(getline(cin,userInput)){
		input.push_back(userInput);
	}

	if(showcount && dupsonly && uniqonly){

	}

	else if(dupsonly && uniqonly){

	}

	else if(showcount && dupsonly){
		countDuplicateLine(input, duplicate);
	}

	else if(showcount && uniqonly){
		countUniqueLine(input, unique);
	}

	else if(dupsonly){
		duplicateLine(input, duplicate);
	}

	else if(showcount){
		occurenceCount(input);
	}

	else if(uniqonly){
		uniqueLine(input);
	}

	else{
		distinct(input, duplicate);
	}

	return 0;
}

bool find(vector<string> V, string c){
	for(int i = 0; i < V.size(); i++){
		if(c == V[i]){
			return true;
		}
	}
	return false;
}

void occurenceCount(vector<string> V){
	string input;
	int count = 1;
	input = V[0];
	for(int i = 1; i < V.size(); i++){
		if(input != V[i]){
			printf("%7lu ", count);
			cout << input << endl;
			//Reset the count
			count = 0;
			//Change the to the ith element in the vector
			input = V[i];
		}
		count++;
	}
	//Count the last element in the vector
	printf("%7lu ", count);
	cout << input << endl;
}

void duplicateLine(vector<string> V1, vector<string> V2){
	for(int i = 0; i < V1.size(); i++){
		if(V1[i] == V1[i+1]){
			//If the value is not in V2, push it to V2
			if(find(V2, V1[i]) == 0){
				V2.push_back(V1[i]);
			}
		}
	}
	for(int i = 0; i < V2.size(); i++){
		cout << V2[i] << endl;
	}
}

void uniqueLine(vector<string> V){
	for(int i = 0; i < V.size(); i++){
		if(V[i] != V[i-1] && V[i] != V[i+1]){
			cout << V[i] << endl;
		}
	}
}

void countDuplicateLine(vector<string> V1, vector<string> V2){
	for(int i = 0; i < V1.size(); i++){
		if(V1[i] == V1[i+1]){
			if(find(V2, V1[i]) == 0){
				V2.push_back(V1[i]);
			}
			if(find(V2, V1[i]) == 1){
				V2.push_back(V1[i]);
			}
		}
	}
	occurenceCount(V2);
}

void countUniqueLine(vector<string> V1, vector<string> V2){
	for(int i = 0; i < V1.size(); i++){
		if(V1[i] != V1[i-1] && V1[i] != V1[i+1]){
			V2.push_back(V1[i]);
		}
	}
	occurenceCount(V2);
}

void distinct(vector<string> V1, vector<string> V2){
	for(int i = 0; i < V1.size(); i++){
		if(V1[i] != V1[i+1]){
			if(find(V2, V1[i]) == 0){
				V2.push_back(V1[i]);
			}
		}
	}
	for(int i = 0; i < V2.size(); i++){
		cout << V2[i] << endl;
	}
}