#include <iostream>
#include <string>
#include <stdlib.h> 
#define MAX 1000 //MAKSIMAL NOMOR ANTRIAN

using namespace std;

string antrian[MAX];
int head=-1;
int tail=-1;

bool IsEmpty(){ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = -1
   if(tail == -1){
       return true;
   }else{
       return false;
   }
}
bool IsFull(){ // FUNGSI UNTUK MENUNJUKAN JIKA TAIL = MAX-1
   if(tail == MAX-1){
       return true;
   }else{
       return false;
   }
}

void TambahAntrian(){
    if (IsFull()){
        cout<<"Antrian sudah penuh ! ";
    }else {
    	head = 0;
        tail++;
        string nama;
        cout << "Masukkan Nama pengantri:";
        cin  >> nama;
        antrian[tail]=nama;
    }
    
}

void KeluarAntrian(){
    if(IsEmpty()){
        cout<<"Antrian sudah kosong ! ";
    }else {
    	cout << "antrian saudara " << antrian[head] << " telah selesai"  << endl;
        for(int a=head;a<tail;a++){
            antrian[a]=antrian[a+1];
        }
        tail--;
        if(tail == -1){
            head = -1;
        }
    }
}

void Clear(){
     head=tail=-1;
}

void print(){
     if(IsEmpty()){
         cout<<"Antrian kosong ! ";

     }else {
         cout << "===============================" << endl;
         for(int a=head;a<=tail;a++){
              
            cout << "\n >> No. Antri " << a+1 << " : " << antrian[a] << endl;
                   
         }
         cout << "\n==============================="<< endl;
     }
}

int main(){
	int pilih;
	do{
		print();
		cout << "\n1. TambahAntrian"
		     << "\n2. KeluarAntrian"
		     << "\n3. Clear"
		     << "\n4. Exit"
		     << "\nBanyak Antrian yang berlangsung: " << tail+1
			 << "\nMasukkan Pilihan : "; cin >> pilih;
		
		switch (pilih){
			case 1:
				TambahAntrian();
				break;
			case 2:
				KeluarAntrian();
				break;
			case 3:
				Clear();
				cout << "Antrian telah dibersihkan" << endl;
				break;
			case 4: 
				cout << "Program Selesai.";
				return 0;
			default:
				cout << "Pilihan Salah";
				break;
		} 
		system ("pause");
		system ("cls");
	}while(pilih != 4);
	
	return 0;
}
