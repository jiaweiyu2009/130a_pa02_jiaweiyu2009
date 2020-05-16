#include "heap.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Heap::insert(int value){
if(this->vdata.size() < 3){
	this->vdata.push_back(value);
}
else{

	this->vdata.push_back(value);
	int level = log(this->vdata.size())/log(2);
	if(level%2 == 0){
		bubbleupMin(this->vdata.size()-1);
	}
	else{
		bubbleupMax(this->vdata.size()-1);
	}

	cout << "inserted " << value <<endl;
}
}



void Heap::insert2(int value, bool bb){
if(bb==false){
if(this->vdata.size() < 3){
	this->vdata.push_back(value);
}
else{

	this->vdata.push_back(value);
	int level = log(this->vdata.size())/log(2);
	if(level%2 == 0){
		bubbleupMin(this->vdata.size()-1);
	}
	else{
		bubbleupMax(this->vdata.size()-1);
	}
	}
}
}



void Heap::bubbleupMin(int i){
	if(i>0){
		int curr = i;
		int parent = (i-1)/2;
		int gp = (((i-1)/2)-1)/2;
	   if(parent != gp){
		if((this->vdata[curr] > this->vdata[parent]) &&(this->vdata[curr] > this->vdata[gp])){
			int temp = this->vdata[curr];
			this->vdata[curr] = this->vdata[parent];
			this->vdata[parent] = temp;
			bubbleupMax((curr-1)/2);
			bubbleupMin((((curr-1)/2)-1)/2);
		}

		else if((this->vdata[curr] < this->vdata[parent]) && (this->vdata[curr] < this->vdata[gp])){
			int temp = this->vdata[curr];
			this->vdata[curr] = this->vdata[gp];
			this->vdata[gp] = temp;
			bubbleupMax((curr-1)/2);
			bubbleupMin((((curr-1)/2)-1)/2);
		}
		else{
			return;
		}
	}
	   else{return;}
	
	}
	else{
		return;
	}


	
}


void Heap::bubbleupMax(int i){

	if(i>0){
		int curr = i;
		int parent = (i-1)/2;
		int gp = (((i-1)/2)-1)/2;

	  if(parent != gp){
		if((this->vdata[curr] < this->vdata[parent]) &&(this->vdata[curr] < this->vdata[gp])){
			int temp = this->vdata[curr];
			this->vdata[curr] = this->vdata[parent];
			this->vdata[parent] = temp;
			bubbleupMin((curr-1)/2);
			bubbleupMax((((curr-1)/2)-1)/2);
		}

		else if((this->vdata[curr] > this->vdata[parent]) && (this->vdata[curr] > this->vdata[gp])){
			int temp = this->vdata[curr];
			this->vdata[curr] = this->vdata[gp];
			this->vdata[gp] = temp;
			bubbleupMin((curr-1)/2);
			bubbleupMax((((curr-1)/2)-1)/2);
		}
		else{
			return;
		}
	  }
	  else{return;}
	}
	else{
		return;
	}
}


void Heap::deleteMin(){
/*	if(this->vdata.size() == 1){
		this->vdata.pop_back();
	}
	else if(this->vdata.size() == 2){
		this->vdata[0] = this->vdata[1];
		this->vdata.pop_back();
	}
	else if(this->vdata.size() == 3){
		this->vdata[0] = this->vdata[2];
		this->vdata.pop_back();
		if(this->vdata[1] < this->vdata[0]){
			int temp = this->vdata[1];
			this->vdata[1] = this->vdata[0];
			this->vdata[0] =temp;
		}
	}
	else if(this->vdata.size() == 4){
		this->vdata[0] = this->vdata[3];
		this->vdata.pop_back();
	}
	else if(this->vdata.size() == 5){
		this->vdata[0] = this->vdata[4];
		this->vdata.pop_back();
		if(this->vdata[0] > this->data[3]){
			int temp = this->vdata[3];
			this->vdata[3] = this->vdata[0];
			this->vdata[0] = temp;
		}
	}
	else if(this->vdata.size() == 6){
		this->vdata[0] = this->vdata[5];
		this->vdata.pop_back();
		if(this->vdata[3] > this->vdata[4]){
			int temp = this->vdata[4];
			this->vdata[4] = this->vdata[0];
			this->vdata[0] = temp;
		}
		else{
			int temp = this->vdata[3];
			this->vdata[3] = this->vdata[0];
			this->vdata[0] = temp;
		}
	}
	else if(this->vdata.size() == 7){
		this->vdata[0] = this->vdata[6];
		this->vdata.pop_back();
		int smallest = 3;
		if (this->vdata[4] < this->vdata[smallest]){
			smallest = 4;
		}
		if (this->vdata[5] < this->vdata[smallest]){
			smallest = 5;
		}
		int temp = this->vdata[smallest];
		this->vdata[smallest] = this->vdata[0];
		this->vdata[0] = temp;
	}
	else{


*/



	int min = vdata[0];
	int last = this->vdata[vdata.size()-1];
	this->vdata[0] = last;
	this->vdata.pop_back();
	bubbledownMin(0);
	cout << "deleted " << min << endl;
}

void Heap::bubbledownMin(int i){
	if(2*i+1 < this->vdata.size()){
		int left = 2*i+1;
		int right = 2*i+2;

		if(this->vdata[i] > this->vdata[left] || this->vdata[i] > this->vdata[right]){
			if(this->vdata[right] > this->vdata[left]){
				int temp = this->vdata[left];
				this->vdata[left] = this->vdata[i];
				this->vdata[i] = temp;
				bubbledownMax(2*i+1);
			}
			else{
				int temp = this->vdata[right];
				this->vdata[right] = this->vdata[i];
				this->vdata[i] = temp;
				bubbledownMax(2*i+2);
			}
		}	
	}
	if((2*(2*i+1))+1 < this->vdata.size()){
		int currLevel = log(i+1) / log(2);
		int nextLevel = currLevel + 2;

		vector<int> v;
		for (int p=0; p < this->vdata.size() ; p++){
			int t = log(p+1)/log(2);
			if (t == nextLevel){
				v.push_back(p);
			}
		}

		int smallest = v[0];
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
			if(this->vdata[*it] < this->vdata[smallest]){
				smallest = *it;
			}
		}

		int temp = this->vdata[smallest];
		this->vdata[smallest] = this->vdata[i];
		this->vdata[i] = temp;
		bubbledownMin(smallest);
	}
}



void Heap::bubbledownMax(int i){
	if(2*i+1 < this->vdata.size()){
		int left = 2*i+1;
		int right = 2*i+2;

		if(this->vdata[i] < this->vdata[left] || this->vdata[i] < this->vdata[right]){
			if(this->vdata[right] < this->vdata[left]){
				int temp = this->vdata[left];
				this->vdata[left] = this->vdata[i];
				this->vdata[i] = temp;
				bubbledownMin(2*i+1);
			}
			else{
				int temp = this->vdata[right];
				this->vdata[right] = this->vdata[i];
				this->vdata[i] = temp;
				bubbledownMin(2*i+2);
			}
		}
	}

	
	if((2*(2*i+1))+1 < this->vdata.size()){
		
		int currLevel = log(i+1) / log(2);
		int nextLevel = currLevel + 2;
		vector<int> v;
		
		for (int p=0; p < this->vdata.size(); p++){
			int t = log(p+1)/log(2);
			if ( t == nextLevel){
				v.push_back(p);
			}
		}

		int biggest = v[0];
		for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
			if(this->vdata[*it] > this->vdata[biggest]){
				biggest = *it;
			}
		}
		
		int temp = this->vdata[biggest];
		this->vdata[biggest] = this->vdata[i];
		this->vdata[i] = temp;
		bubbledownMax(biggest);
	}
}


void Heap::deleteMax(){
	if (this->vdata.size() > 3){
		int larger = 1;
		if(this->vdata[2] > this->vdata[1]){
			larger = 2;
		}

	int max = this->vdata[larger];
	int last = this->vdata[vdata.size()-1];
	this->vdata[larger] = last;
	this->vdata.pop_back();
	bubbledownMax(larger);
	cout << "deleted " << max << endl;
	}
	else{return;}
}


void Heap::print(){
cout << "heap = ";
	for(auto it = this->vdata.begin(); it != this->vdata.end(); it++){
		cout << *it << " ";
	}

	//cout << "\n";
}

void Heap::getMin(){
	cout << "min = " << this->vdata[0] << endl;

}

void Heap::getMax(){
	int larger = this->vdata[1];
	if(this->vdata[2] > larger){
		larger = this->vdata[2];
	}
	cout << "max = " << larger << endl;
}
