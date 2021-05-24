#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <windows.h> //Dùng để sử dụng system("cls") - lệnh xóa màn hình
#include <vector>
#include <sstream>
#include <ctime>
#include <conio.h>

int kiem_tra_id( string id );

bool kiem_tra_password( string pass );

string lay_ra_pass( string id );

string lay_ra_money( string id );

string lay_ra_active( string id );

bool kiem_tra_dang_nhap( string id ,string pass);

int kiem_tra_trang_thai_the( string id );

void changeactive( string id );

void changepass( string id , string newpass );

void changemoney( string id , string newmoney );

void thay_doi_ngan_hang( long int tongtien , int soto500 , int soto200 , int soto100 , int soto50 , int soto20 , int soto10 );

int start_from_500( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int start_from_200( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int start_from_100( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int start_from_50( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int start_from_20( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int start_from_10( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 );

int lay_ra_stt( string id );

string get_time_now();

void bo_sung_lsdd( string id , string newlsdd );

void lsdd_guitien( string id , string money , string sodu );

void lsdd_ruttien( string id , string money , string sodu );

void lsdd_chuyentien( string id , string money , string sodu , string id1 );

void lsdd_nhantien( string id , string money , string sodu , string id1 );

string nhap_mat_khau();

int phi_dich_vu( long int money );
