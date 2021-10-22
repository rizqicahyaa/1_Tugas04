#include<iostream>

using namespace std;

int main(){
	menu:
	int jumlah_barang, harga_barang, harga=0, harga_total, i=1, jawab;
	
	cout<<"Menghitung Total Belanjaan\n";
	cout<<"Jumlah Barang = ";cin>>jumlah_barang;
	while(i<=jumlah_barang){
		cout<<"Masukkan Harga Barang Ke "<<i<<" = Rp.";cin>>harga_barang;
		harga=harga+harga_barang;
		i++;
	}
	
	if (harga>=500000){
		harga_total=harga-(harga*0.1);
	}
	else if(harga>200000 && jumlah_barang<=500000){
		harga_total=harga-(harga*0.5);
	}
	else if(harga<=200000){
		harga_total=harga;	
	}
	
	cout<<"\nHarga Asli = Rp. "<<harga;
	cout<<"\nHarga Setelah Di Diskon = Rp. "<<harga_total;
	
	cout<<"\n";
	cout<<"\nKembali Ke Menu [0]Tidak [1]Iya = "; cin>>jawab;
	if(jawab==1){
		system("cls");
		goto menu;
	}
	else if(jawab==0){
		cout<<"\n";
		cout<<"Terima Kasih";
	}
	
	return 0;
}
