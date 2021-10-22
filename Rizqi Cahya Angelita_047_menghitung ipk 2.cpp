#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  menu:
  int i, j, nilai, jumlah_semester, jumlah_matakuliah, sks[50][30], jumlah_nilai, sks_semester[14], jumlah_sks, total_sks=0, jawab;
  char nilai_huruf[50][30], matakuliah[50][50][30];
  float ipk,nr[14], total_nr=0;

  cout<<"\tMenghitung IPK Mahasiswa\n";

  cout<<"\nMasukkan Jumlah Semester = ";
  cin>>jumlah_semester;

  if (jumlah_semester < 2 || jumlah_semester > 14) {
    cout<<"Jumlah Semester Salah!\n";
    return 0;
  }
  else {
    for (i = 0; i < jumlah_semester; i++) {
      jumlah_nilai = 0;
      jumlah_sks = 0;
      cout<<"\nMasukkan Jumlah Mata Kuliah Semester " << i + 1 << " = ";
      cin>>jumlah_matakuliah;
      if (jumlah_matakuliah < 2) {
        cout<<"Jumlah Mata Kuliah Kurang Dari 2 Setiap Semester\n";
        return 0;
      }
      else {

        for (j = 0; j < jumlah_matakuliah; j++) {
          cout<<"\nMasukkan Mata Kuliah Ke " << j + 1;
          cout<<"\n";
          cout<<"Masukkan Nama Mata Kuliah = ";
          cin>>matakuliah[i][j];
          cout<<"Masukkan Jumlah SKS Mata Kuliah = ";
          cin>>sks[i][j];
          cout<<"Masukkan Nilai Mata Kuliah = ";
          cin>>nilai_huruf[i][j];

          if (nilai_huruf[i][j] == 'A') {
            nilai = 4 * sks[i][j];
          }
          else if (nilai_huruf[i][j] == 'B') {
            nilai = 3 * sks[i][j];
          }
          else if (nilai_huruf[i][j] == 'C') {
            nilai = 2 * sks[i][j];
          }
          else if (nilai_huruf[i][j]=='D') {
            nilai = 1 * sks[i][j];
          }
          else if (nilai_huruf[i][j]=='E') {
            nilai = 0 * sks[i][j];
          }
          else {
            cout << "Input Salah!\n";
            return 0;
          }
          jumlah_nilai = jumlah_nilai + nilai;
          jumlah_sks = jumlah_sks + sks[i][j];
        }
        if(jumlah_sks > 24){
          cout << "Jumlah SKS Semester Lebih Dari 24\n";
          return 0;
        } else {
          sks_semester[i] = jumlah_sks;
          nr[i] = jumlah_nilai / jumlah_sks;
        }   
      }
    }
  }
  
  cout<<"\n";
  cout<<"\t\tTranskrip Nilai";
  cout<<"\n";
  for(i = 0; i < jumlah_semester; i++){
    cout<<"\n\t\tHasil Semester "<<i+1;
    cout<<"\n";
	cout<<setw(12) << "Mata Kuliah" <<setw(12) <<"SKS" <<setw(12) <<"Nilai\n";
    for(j = 0; j < jumlah_matakuliah; j++){
      cout<<"\n"; 
	  cout<<setw(12) <<matakuliah[i][j] <<setw(12) <<sks[i][j] <<setw(12) <<nilai_huruf[i][j];
    }
    cout<<"\n\nSKS\t\t = " <<sks_semester[i];
    cout<<fixed <<setprecision(2) <<"\nNR\t\t = " <<nr[i];
    total_sks = total_sks + sks_semester[i];
    total_nr = total_nr + nr[i];
    cout<<"\n";
  }
  ipk = total_nr/jumlah_semester;
  cout<<"\nTotal SKS\t = "<< total_sks;
  cout<<fixed <<setprecision(2) <<"\nIPK\t\t = " <<ipk;
  cout<<"\n";
  
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
