#include<iostream>
#define maxstack 7

using namespace std;

struct STACK{
	int s[7];
	int top;
};
struct STACK st;
void push(int data){
	if(st.top==maxstack){
		cout<<"data penuh"<<endl;
	}else{
		st.top = st.top +1;
		st.s[st.top] = data;
		cout<<"data ditambahkan"<<endl;
	}

}
void pop(){
	if(st.top==-1){
		cout<<"data kosong"<<endl;
	}else{
		st.top = st.top-1;
		cout<<"data dihapus"<<endl;
	}
	
}

void show(){
   if(st.top==-1){
		cout<<"data kosong, tidak ada yang bisa ditampilkan";
	}else{
		for(int x=0;x<=st.top;x++){
			cout<<st.s[x]<<"=>";
		}
		cout<<endl;
	}
}
int main(){
	st.top = -1;
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	pop();
	show();	
}