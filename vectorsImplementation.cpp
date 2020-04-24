#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> V1;

	for(int i=1;i<=10;i++){
		V1.push_back(i*10);
	}	

	cout<<"\nITERATORS";
	cout<<"\n\nOutput of begin() and end() : ";

	for(auto i=V1.begin();i!=V1.end();i++){
		cout<<*i<<" ";
	}

	cout<<"\nOutput of cbegin() and cend() : ";

	for(auto i1=V1.cbegin();i1!=V1.cend();i1++){
		cout<<*i1<<" ";
	}

	cout<<"\nOutput of rbegin() and rend() : ";

	for(auto i2=V1.rbegin();i2!=V1.rend();i2++){
		cout<<*i2<<" ";
	}
	cout<<"\nOutput of crbegin() and crend() : ";

	for(auto i3=V1.crbegin();i3!=V1.crend();i3++){
		cout<<*i3<<" ";
	}

	cout<<"\n\nCAPACITY";
	cout<<"\n";

	cout<<"\nSize : "<<V1.size();
	cout<<"\nCapacity : "<<V1.capacity();
	cout<<"\nMax_Size : "<<V1.max_size();
	
	V1.resize(4);
	cout<<"\nAfter Resizing the size is : "<<V1.size();
	cout<<"\n\nNow the elements are : ";
	for(auto i4=V1.begin();i4!=V1.end();i4++){
		cout<<*i4<<" ";
	}
	cout<<"\n\nTo check if Vector is empty or not : "<<V1.empty();
	cout<<"\n\nNow shrink the vector to fit its elements:";
	V1.shrink_to_fit();
	cout<<"\nElements are: ";
	for(auto i5=V1.begin();i5!=V1.end();i5++){
		cout<<*i5<<" ";
	}

	cout<<"\n\nNow let's check whether if resizing it will retain the lost elements or not :";
	V1.resize(5);
	cout<<"\n\nSo i have increased the size to 5, Now let's check what the elements are :";
	cout<<"\nElements are : ";
	for(auto i6=V1.begin();i6!=V1.end();i6++){
		cout<<*i6<<" ";
	}
	cout<<"\n\nConclusion : once the elements are lost while resizing can not be retained, as performed above";
	cout<<"\n";

	cout<<"\nELEMENT ACCESS";
	cout<<"\n\nWe can access elements of a vector by either of 2 ways :";
	cout<<"\n1. vectorName[index] i.e. V1[3] = "<<V1[3];
	cout<<"\n2. vectorName.at(index) i.e. V1.at(3) = "<<V1.at(3);

	cout<<"\nFor Accessing first element : V1.front() = "<<V1.front();
	cout<<"\n\t\t& For last element : V1.back() = "<<V1.back();

	cout<<"\n\nNo we will use (for checking address) vectorName.data() : V1.data = "<<V1.data();

	cout<<"\n\nMODIFIERS";
	cout<<"\n\nFor replacing old values of vector elements with new ones, We use  vectorName.assign(T, N): It fills vector with the given element N ,T times.";
	cout<<"\nVector after V1.assign(7,8) = ";
	V1.assign(7,8);
	for(int i=0;i<V1.size();i++){
		cout<<V1[i]<<" ";
	}
	cout<<"\n\nFor inserting at last we use push_back(element): ex. V1.push_back(9)" ;
	V1.push_back(9);
	int n=V1.size();
	cout<<"\nAfter push_back(9), Last element is : "<<V1[n-1];
	cout<<"\n\nFor removing last element we use pop_back()";
	V1.pop_back();
	n=V1.size();
	cout<<"\nAfter pop_back(), Last element is : "<<V1[n-1];

	cout<<"\n\nFor inserting element before an element at specified position we use insert(position,element)";
	V1.insert(V1.begin(),6);
	cout<<"\nAfter V1.insert(V1.begin(),6),the Vector is :";
	for (int i = 0; i < V1.size(); i++) 
        cout << V1[i] << " "; 

	cout<<"\nFor removing element from specified position we use erase(position).";
	V1.erase(V1.begin());
	cout<<"\nAfter V1.erase(v.begin()), First element is = "<<V1[0];

	cout<<"\n\nFor removing all element we use clear()";
	V1.clear();
	cout<<"\nAfter V1.clear(), Vector size is : "<<V1.size();
	cout<<"\n";

	cout<<"\nFor SWAPPING, we use V1.swap(V2)";
	cout<<"\nEXAMPLE: ";
	vector<int> v1, v2; 
    v1.push_back(1); 
    v1.push_back(2); 
    v2.push_back(3); 
    v2.push_back(4); 
  
    cout << "\n\nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 
  
    // Swaps v1 and v2 
    v1.swap(v2); 
  
    cout << "\nAfter Swap \nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 

	cout<<"\n";
} 
