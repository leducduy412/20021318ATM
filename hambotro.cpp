#include "hambotro.h"

int kiem_tra_id ( string id ) {
    if ( id.length() < 8 || id.length() > 12 )  return -1; else {
        for( int i =  0 ; i < id.length() ; i ++ ) {
            if ( id[i] < '0' || ( id[i] > '9' && id[i] < 'a' ) || id[i] > 'z' ) return -1;
        }
        ifstream f( "thongtinkhachhang.txt" );
        if ( f.is_open() ) {
            while ( !f.eof() ) {
                string s;
                getline( f , s , ' ' );
                if ( id == s ) return 0;
                getline( f , s );
            }
        }
        f.close();
        return 1;
    }
}

bool kiem_tra_password( string pass ) {
    if ( pass.length() < 8 || pass.length() > 16 ) return false;
    for ( int i = 0 ; i < pass.length() ; i++ ){
        if ( pass[i] == 8 ) return false;
    }
    return true;
}

string lay_ra_pass( string id ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string thamchieu1,thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ){
                getline( f , thamchieu2 , ' ' );
                return thamchieu2;
            } else getline( f , thamchieu2 );
        }
    }
}

string lay_ra_money( string id ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string thamchieu1,thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ){
                getline( f , thamchieu2 , ' ' );
                getline( f , thamchieu2 , ' ' );
                return thamchieu2;
            } else getline( f , thamchieu2 );
        }
    }
}

string lay_ra_active( string id ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string thamchieu1,thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ){
                getline( f , thamchieu2 , ' ' );
                getline( f , thamchieu2 , ' ' );
                getline( f , thamchieu2 );
                return thamchieu2;
            } else getline( f , thamchieu2 );
        }
    }
    f.close();
}

bool kiem_tra_dang_nhap( string id ,string pass) {
    if ( lay_ra_pass ( id ) != pass ) return false; else return true;
}

int kiem_tra_trang_thai_the( string id ) {
    if (kiem_tra_id ( id ) == 1 || kiem_tra_id( id) == -1 ) return 0;
    if ( lay_ra_active( id ) == "1" ) return 1; else {
        if ( lay_ra_active( id ) == "0" ) return -1;
    }
}

void changeactive( string id ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string file[10000];
        int i=0;
        string thamchieu1, thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ) {
                string a,b;
                getline( f , a , ' ' );
                getline( f , b , ' ' );
                getline( f , thamchieu2 );
                if ( thamchieu2 == "1" ) thamchieu2 = "0"; else thamchieu2 = "1";
                file[i]+=thamchieu1;
                file[i]+=" ";
                file[i]+=a;
                file[i]+=" ";
                file[i]+=b;
                file[i]+=" ";
                file[i]+=thamchieu2;
            } else {
                getline( f , thamchieu2 );
                file[i]+=thamchieu1;
                file[i]+=" ";
                file[i]+=thamchieu2;
            }
            i++;
        }
        f.close();
        //Xóa toàn bộ file
        ofstream ofs ("thongtinkhachhang.txt", std::ofstream::out);
        ofs.close();
        //Ghi lại vào file
        fstream s( "thongtinkhachhang.txt" , std::ios::out | std::ios::app );
        for ( int j = 0 ; j < i - 1 ; j++ ) s<<file[j]<<endl;
        s.close();
    }
}

void changepass( string id , string newpass ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string file[10000];
        int i=0;
        string thamchieu1, thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ) {
                string b;
                getline( f , thamchieu2 , ' ' );
                getline( f , b );
                thamchieu2 = newpass;
                file[i]+=thamchieu1;
                file[i]+=" ";
                file[i]+=thamchieu2;
                file[i]+=" ";
                file[i]+=b;
            } else {
                getline( f , thamchieu2 );
                file[i]+=thamchieu1;
                file[i]+=" ";
                file[i]+=thamchieu2;
            }
            i++;
        }
        f.close();
        //Xóa toàn bộ file
        ofstream ofs ("thongtinkhachhang.txt", std::ofstream::out);
        ofs.close();
        //Ghi lại vào file
        fstream s( "thongtinkhachhang.txt" , std::ios::out | std::ios::app );
        for ( int j = 0 ; j < i - 1 ; j++ ) s<<file[j]<<endl;
        s.close();
    }
}

void changemoney( string id , string newmoney ) {
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        string file[10000];
        int i=0;
        string thamchieu1, thamchieu2;
        while ( !f.eof() ) {
            getline( f , thamchieu1 , ' ' );
            if ( thamchieu1 == id ) {
                string a,b;
                getline( f , a , ' ' );
                getline( f , thamchieu2 , ' ' );
                getline( f , b );
                thamchieu2 = newmoney;
                file[i] += thamchieu1;
                file[i] += " ";
                file[i] += a;
                file[i] += " ";
                file[i] += thamchieu2;
                file[i] += " ";
                file[i] += b;
            } else {
                getline( f , thamchieu2 );
                file[i] += thamchieu1;
                file[i] += " ";
                file[i] += thamchieu2;
            }
            i++;
        }
        f.close();
        //Xóa toàn bộ file
        ofstream ofs ("thongtinkhachhang.txt", std::ofstream::out);
        ofs.close();
        //Ghi lại vào file
        fstream s( "thongtinkhachhang.txt" , std::ios::out | std::ios::app );
        for ( int j = 0 ; j < i - 1 ; j++ ) s<<file[j]<<endl;
        s.close();
    }
}

void thay_doi_ngan_hang( long int tongtien , int soto500 , int soto200 , int soto100 , int soto50 , int soto20 , int soto10 ) {
    ifstream f( "nganhang.txt" );
    long int tien;
    int to500,to200,to100,to50,to20,to10;
    if ( f.is_open() ) {
        f >> tien >> to500 >> to200 >> to100 >> to50 >> to20 >> to10;
        tien += tongtien;
        to500 += soto500;
        to200 += soto200;
        to100 += soto100;
        to50 += soto50;
        to20 += soto20;
        to10 += soto10;
    }
    f.close();
    //Xóa toàn bộ file
    ofstream ofs ("nganhang.txt", std::ofstream::out);
    ofs.close();
    //Ghi lại vào file
    fstream s( "nganhang.txt" , std::ios::out | std::ios::app );
    s << tien << endl << to500 << endl << to200 << endl << to100 << endl << to50 << endl << to20 << endl << to10 ;
    s.close();
}

int start_from_500( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 500000 && to500 > 0 ) {
        tienrut -= 500000;
        ra500++;
        to500 --;
    }
    while ( tienrut >= 200000 && to200 > 0 ) {
        tienrut -= 200000;
        ra200++;
        to200 --;
    }
    while ( tienrut >= 100000 && to100 > 0 ) {
        tienrut -= 100000;
        ra100++;
        to100 --;
    }
    while ( tienrut >= 50000 && to50 > 0 ) {
        tienrut -= 50000;
        ra50++;
        to50 --;
    }
    while ( tienrut >= 20000 && to20 > 0 ) {
        tienrut -= 20000;
        ra20++;
        to20 --;
    }
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra500+ra200+ra100+ra50+ra20+ra10;
}

int start_from_200( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 200000 && to200 > 0 ) {
        tienrut -= 200000;
        ra200++;
        to200 --;
    }
    while ( tienrut >= 100000 && to100 > 0 ) {
        tienrut -= 100000;
        ra100++;
        to100 --;
    }
    while ( tienrut >= 50000 && to50 > 0 ) {
        tienrut -= 50000;
        ra50++;
        to50 --;
    }
    while ( tienrut >= 20000 && to20 > 0 ) {
        tienrut -= 20000;
        ra20++;
        to20 --;
    }
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra200+ra100+ra50+ra20+ra10;
}

int start_from_100( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 100000 && to100 > 0 ) {
        tienrut -= 100000;
        ra100++;
        to100 --;
    }
    while ( tienrut >= 50000 && to50 > 0 ) {
        tienrut -= 50000;
        ra50++;
        to50 --;
    }
    while ( tienrut >= 20000 && to20 > 0 ) {
        tienrut -= 20000;
        ra20++;
        to20 --;
    }
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra100+ra50+ra20+ra10;
}

int start_from_50( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 50000 && to50 > 0 ) {
        tienrut -= 50000;
        ra50++;
        to50 --;
    }
    while ( tienrut >= 20000 && to20 > 0 ) {
        tienrut -= 20000;
        ra20++;
        to20 --;
    }
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra50+ra20+ra10;
}

int start_from_20( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 20000 && to20 > 0 ) {
        tienrut -= 20000;
        ra20++;
        to20 --;
    }
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra20+ra10;
}

int start_from_10( long int tienrut , int to500 , int to200 , int to100 , int to50 , int to20 , int to10 , int &ra500 , int &ra200 , int &ra100 , int &ra50 , int &ra20 , int &ra10 ) {
    while ( tienrut >= 10000 && to10 > 0 ) {
        tienrut -= 10000;
        ra10++;
        to10 --;
    }
    if ( tienrut > 0 ) return -1; else return ra10;
}

int lay_ra_stt( string id ) {
    int i = 1;
    ifstream f( "thongtinkhachhang.txt" );
    if ( f.is_open() ) {
        while ( !f.eof() ) {
            string s;
            getline( f , s , ' ' );
            if ( id == s ) return i;
            i++;
            getline( f , s );
        }
    }
    f.close();
}

string get_time_now() {
    time_t now = time(0);
    string s = "[";
    s += ctime(&now);
    s[s.length() -1] = ']';
    return s;
}

void bo_sung_lsdd( string id , string newlsdd ) {
    int dem = 0;
    int stt = lay_ra_stt( id );
    vector<string> file;
    string s;
    ifstream f( "lichsugiaodich.txt" );
    if ( f.is_open() ) {
        while ( !f.eof() ) {
            getline( f , s );
            file.push_back( s );
            if ( s == "-----" ) dem++;
            if ( dem == stt ) {
                getline( f , s );
                while ( s != "-----" ) {
                    file.push_back( s );
                    getline( f , s );
                }
                file.push_back( newlsdd );
                file.push_back( s );
                dem++;
            }
        }
    }
    f.close();
    //Xóa toàn bộ file
    ofstream ofs ("lichsugiaodich.txt", std::ofstream::out);
    ofs.close();
    //Ghi lại vào file
    fstream k( "lichsugiaodich.txt" , std::ios::out | std::ios::app );
    for ( int i = 0 ; i < file.size() -1; i++ ) {
        k << file[i] << endl;
    }
    k << file[file.size()-1];
    k.close();
}

void lsdd_guitien( string id , string money , string sodu ) {
    string s = get_time_now();
    s += " So tien GD : +" ;
    s += money;
    s += " VND ( Gui tien ). So du hien tai : ";
    s += sodu;
    s += " VND.";
    bo_sung_lsdd( id , s );
}

void lsdd_ruttien( string id , string money , string sodu ) {
    string s = get_time_now();
    s += " So tien GD : -";
    s += money;
    s += " VND ( Rut tien ). So du hien tai : ";
    s += sodu;
    s += " VND.";
    bo_sung_lsdd( id , s );
}

void lsdd_chuyentien( string id , string money , string sodu , string id1 ) {
    string s = get_time_now();
    s += " So tien GD : -";
    s += money;
    s += " VND ( CK toi ";
    s+= id1;
    s+= " ). So du hien tai : ";
    s += sodu;
    s += " VND.";
    bo_sung_lsdd( id , s );
}

void lsdd_nhantien( string id , string money , string sodu , string id1 ) {
    string s = get_time_now();
    s += " So tien GD : +";
    s += money;
    s += " VND ( CK tu ";
    s += id1;
    s += " ). So du hien tai : ";
    s += sodu;
    s += " VND.";
    bo_sung_lsdd( id , s );
}

string nhap_mat_khau() {
    string password;
    char a = getch();
    while ( a != 13 && a != 8) {
        cout << "*";
        password += a;
        a = getch();
    }
    cout << endl;
    return password;
}
