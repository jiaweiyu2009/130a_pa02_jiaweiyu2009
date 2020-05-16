#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <queue>
#include "heap.h"
using namespace std;

int main(int argc, char** argv){
fstream file;
int word;
string filename;
Heap mmheap;
//filename = "PA1_dataset.txt";
filename = "small.txt";
file.open(filename.c_str());
while (file >>word){
	mmheap.insert2(word,false);
}

string str = argv[1];
queue<string>q;

stringstream ss(str);
while (ss.good()){
    string substr;
    getline(ss, substr, ',');
    q.push(substr);
}

while (!q.empty()){
string s = q.front();

//////////////////////////////////////////////////////////////
if (s.find("insert") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}

string key = s.substr(indexOfSpace+1, s.length()-1);
stringstream geek(key);
int x;
geek >> x;
	mmheap.insert(x);
}

//////////////////////////////////////////////////////////
else if(s.find("getMin") != std::string::npos){
	mmheap.getMin();
}

///////////////////////////////////////////////////////////
else if(s.find("getMax") != std::string::npos){
	mmheap.getMax();
}

////////////////////////////////////////////////////////////
else if(s.find("deleteMin") != std::string::npos){
	mmheap.deleteMin();
}

///////////////////////////////////////////////////////////
else if(s.find("deleteMax") != std::string::npos){
	mmheap.deleteMax();
}

//////////////////////////////////////////////////////////
else if(s.find("printHeap") != std::string::npos){
	mmheap.print();
}

q.pop();
}

return 0;

}
