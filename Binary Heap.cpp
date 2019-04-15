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

	void get_cs(){ cout << "cs = " << cs << endl;}

	//Insert function (enter the data and then increase cs by 1)
	void insert(int data){
		//If you exceed the max size
		if(cs==ms){cout << "Array limit reached.Function terminated." << endl;
			return;
		}

		a[cs] = data;
		//Increase curr size
		cs++;
		//Then comes the checking
		cor_bot(cs-1);
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

		//Take the last value and put it in the first place
		a[0] = a[cs-1];
		//Reduce cs
		cs--;
		//Correction
		cor_top(0);
		return res;
	}

	//Decrease key (you reduce the value stored in one of the indexes)
	void deckey(int i, int nval){
		//If the index doesn't exist
		if(i>=cs){cout << "No such value in array.Function Terminated" << endl;
			return;
		}
		//Store the previous value
		int cval = a[i];
		//Decrease the key value
		a[i] = nval;
		//correction
		//If the new value is smaller
		if(cval > nval){
			cor_bot(i);
		}
		
		//If the new value is larger
		if(cval < nval){
			cor_top(i);
		} 
	}

	//Delete
	void Delete(int i){
		//converting pos to index
		i--;

		//If the index doesn't exist
		if(i>=cs){cout << "No such value in array.Function Terminated" << endl;
			return;
		} 

		//Saving old value
		int cval = a[i];
		
		//Putting last element in place of the element to be deleted.
		a[i] = a[cs-1];

		//Reducing the arr size
		cs--;
	
		//correction
		//If the new value is smaller
		if(cval > a[cs]){
			cor_bot(i);
		}

		//If the new value is larger
		if(cval < a[cs]){
			cor_top(i);
		}
		
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

	//The Correcion Function from top.
	void cor_top(int i){
		int si = i;
		if(a[i]>a[l(i)]){
			si = l(i);
		}
		else if(a[i]>a[r(i)]){
			si = r(i);
		}
		if(si != i){swap(i,si);

		//Recurse the function
		cor_top(si);
		}
	}

	//The correction function from bottom
	void cor_bot(int i){
		if(i==0){return;}
		int si = p(i);

		//If right child doesn't exist
		if(r(si)>=cs){
			if(a[l(p(i))] < a[r(p(i))]){si = l(p(i));}
		}

		else{
			if(a[l(p(i))] < a[r(p(i))]){si = l(p(i));}
			else if(a[l(p(i))] > a[r(p(i))]){si = r(p(i));}
		}

		if(a[si] < a[p(i)]){
			swap(si,p(i));
		
		//And then recur for it.
		cor_bot(p(i));
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
