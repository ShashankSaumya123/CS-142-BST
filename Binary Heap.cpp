//Binary Heap
#include<iostream>
using namespace std;
class BH{
	public:
	int cs = 0;
	int ms = 50;
	int *a = new int [ms];
	
	//left, right and parent functions...
	int l(int i){return (2*i)+1;}
	int r(int i){return (2*i)+2;}
	int p(int i){return (i-1)/2;}

	//Insert function (enter the data and then increase cs by 1)
	void insert(int data){
		//If you exceed the max size
		if(cs==ms){cout << "Array limit reached.Function terminated." << endl;
			return;
		}

		a[cs] = data;
		//Increase curr size
		cs++;
		//Then comes the checking func.
		correct();
	}

	//Get the minimum
	int getmin(){
		//If the heap is empty
		if(cs==0){cout << "No value in array.Function Terminated" << endl;
			return 0;}
		return a[0];
	}

	//Extract the minimum
	int extmin(){
		//If the heap is empty
		if(cs==0){cout << "No value in array.Function Terminated" << endl;
			return 0;}

		int res = a[0];

		//Move the arrary left to remove first element
		for(int j=0;j<cs;j++){
			a[j-1] = a[j];
		}
		//Reduce cs
		cs--;
		//Correction
		correct();
		return res;
	}

	//Decrease key (you reduce the value stored in one of the indexes)
	void deckey(int i, int nval){
		//If the index doesn't exist
		if(i>=cs){cout << "No such value in array.Function Terminated" << endl;
			return;
		} 
		//Decrease the key value
		a[i] = nval;
		//correction
		correct();
	}

	//Delete
	void Delete(int i){
		//If the index doesn't exist
		if(i>=cs){cout << "No such value in array.Function Terminated" << endl;
			return;
		} 
		//Move the array left from the index to remove that value
		for(int j=i+1;j<cs;j++){
			a[j-1]=a[j];
		}
		//Reduce cs
		cs--;
		//Correct it plz
		correct();
	}

	//Display (just print in loops)
	void Display(){
		//If the index doesn't exist
		if(cs==0){cout << "No values in array.Function Terminated" << endl;
			return;
		} 
		for(int i=0;i<cs;i++){cout << a[i] << " ";}
		cout << endl;
	}

	//The Correcion Function
	void correct(){
		for(int i=(cs-1);i>=0;i--){
			if(a[i]<a[p(i)]){swap(i,p(i));}
		}
	}

	//The swap function used in correction
	void swap(int x, int y){
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
};

int main(){
	BH b1;
	b1.Display();
	//Insert something
	for(int i=0;i<10;i++)
	{
		b1.insert(i+1);
	}
	b1.Display();
	b1.insert(54);
	b1.Display();
return 0;
}
