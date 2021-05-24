#include "hambotro.h"
#include "mayruttien.h"

void dangky(){
    cout << "Tai khoan : ";
    string id;
    cin >> id;
    if ( kiem_tra_id( id ) != 1 ) {
        if ( kiem_tra_id( id ) == -1 ) cout << "Tai khoan khong hop le! Vui long nhap lai." << endl;
        if ( kiem_tra_id( id ) == 0 ) cout << "Tai khoan da duoc su dung! Vui long nhap lai." << endl;
        dangky();
    } else {
        cout << "Mat khau : ";
        string pass1,pass2;
        pass1 = nhap_mat_khau();
        while ( kiem_tra_password( pass1 ) == false ) {
            cout << "Mat khau khong hop le! Vui long nhap lai." << endl;
            cout << "Mat khau : ";
            pass1 = nhap_mat_khau();
        }
        cout << "Nhap lai mat khau: ";
        pass2 = nhap_mat_khau();
        while ( pass2 != pass1 ) {
            cout << "Mat khau khong khop! Vui long nhap lai." << endl;
            cout << "Nhap lai mat khau : ";
            pass2 = nhap_mat_khau();
        }
        fstream f( "thongtinkhachhang.txt" , std::ios::out | std::ios::app );
        // Sử dụng std::ios::app để di chuyển đến cuối file và ghi vào đó ( nếu đơn thuần dùng ofstream thì dữ liệu file ban đầu sẽ mất hết )
        f << id << " " << pass1 << " " << "0" << " " << "1" << endl;
        f.close();
        fstream s( "lichsugiaodich.txt" , std::ios::out | std::ios::app );
        s << "-----" << endl;
        s.close();
        cout << "Ban da dang ky thanh cong! Nhap 0 de quay lai : ";
        int re;
        cin >> re;
        if ( re == 0 ) start();
    }
}

void dangnhap(){
    cout << "Tai khoan : " ;
    string id;
    cin >> id;
    if ( kiem_tra_id ( id ) != 0) {
        if ( kiem_tra_id ( id ) == -1 ) cout << "Tai khoan khong hop le! Vui long nhap lai." << endl;
        if ( kiem_tra_id ( id ) == 1 ) cout << "Tai khoan khong ton tai! Vui long nhap lai." << endl;
        dangnhap();
    } else {
        if ( lay_ra_active( id ) == "0" ) {
            cout << "Tai khoan cua ban da bi khoa tam thoi! Nhan 0 de quay lai : ";
            int re;
            cin >> re;
            if ( re == 0 ) start();
        }
        cout << "Mat khau : ";
        string pass;
        pass = nhap_mat_khau();
        int solansai=0;
        while ( kiem_tra_dang_nhap( id , pass ) == false ) {
            solansai++;
            if ( solansai >= 5 ) {
                changeactive( id );
                cout << "Tai khoan cua ban da bi khoa tam thoi do nhap sai mat khau 5 lan lien tiep!" << endl;
                cout << "Nhap 0 de quay lai : " ;
                int re;
                cin>>re;
                if ( re == 0 ) start();
                break;
            }
            cout << "Mat khau khong dung! Vui long nhap lai." << endl;
            cout << "Mat khau : ";
            pass = nhap_mat_khau();
        }
        if ( kiem_tra_dang_nhap ( id , pass ) == true ) {
            cout << "Dang nhap thanh cong!" << endl;
            menu( id );
        }
    }
}

void kiem_tra_atm() {
    cout << "Tinh trang may : Hoat dong" << endl;
    ifstream f( "nganhang.txt" );
    if ( f.is_open() ) {
        long int tien;
        int to500,to200,to100,to50,to20,to10;
        f >> tien >> to500 >> to200 >> to50 >> to20 >> to10;
        cout << "So tien trong may : " << tien << " VND. Gom : " << endl;
        cout << "500.000 VND : " << to500 << " to." <<endl;
        cout << "200.000 VND : " << to200 << " to." <<endl;
        cout << "100.000 VND : " << to10 << " to." <<endl;
        cout << "50.000 VND : " << to50 << " to." <<endl;
        cout << "20.000 VND : " << to20 << " to." <<endl;
        cout << "10.000 VND : " << to10 << " to." <<endl;
        cout << "Nhan 0 de quay lai : " ;
        int re;
        cin >> re;
        if ( re == 0 ) start();
    }
}

void them_tien_vao_may() {
    cout << "THEM TIEN VAO MAY ATM " << endl;
    cout << "Nhap TK ADMIN : ";
    string ad;
    cin >> ad;
    if ( ad != "admin1210" ) {
        cout << "Tai khoan khong hop le! Nhan 0 de quay lai : ";
        int re;
        cin >> re;
        if ( re == 0 ) start();
    } else {
        cout << "Nhap mat khau : ";
        string pass;
        pass = nhap_mat_khau();
        if ( pass != "12102002" ) {
            cout << "Mat khau khong hop le! Nhan 0 de quay lai : ";
            int re;
            cin >> re;
            if ( re == 0 ) start();
        } else {
            system("cls");
            cout << "Vui long nhap so luong cac menh gia! Luu y so luong cua tung menh gia phai la mot so nguyen lon hon hoac bang 0." << endl;
            cout << "1. 500.000 VND : ";
            int soto500,soto200,soto100,soto50,soto20,soto10;
            cin >> soto500;
            while ( soto500 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "1. 500.000 VND : ";
                cin >> soto500;
            }
            cout << "2. 200.000 VND : ";
            cin >> soto200;
            while ( soto200 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "2. 200.000 VND : ";
                cin >> soto200;
            }
            cout << "3. 100.000 VND : ";
            cin >> soto100;
            while ( soto100 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "3. 100.000 VND : ";
                cin >> soto100;
            }
            cout << "4. 50.000 VND : ";
            cin >> soto50;
            while ( soto50 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "4. 50.000 VND : ";
                cin >> soto50;
            }
            cout << "5. 20.000 VND : ";
            cin >> soto20;
            while ( soto20 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "5. 20.000 VND : ";
                cin >> soto20;
            }
            cout << "6. 10.000 VND : ";
            cin >> soto10;
            while ( soto10 < 0 ) {
                cout << "So luong khong hop le! Vui long nhap lai."<<endl;
                cout << "6. 10.000 VND : ";
                cin >> soto10;
            }
            long int sum;
            sum = soto500*500000+soto200*200000+soto100*100000+soto50*50000+soto20*20000+soto10*10000;
            int quaylai;
            if ( sum == 0 ) {
                cout << "Cap nhat khong hop le! Nhan 0 de quay lai : ";
                cin >> quaylai;
                if ( quaylai == 0 ) start();
            }
            thay_doi_ngan_hang( sum , soto500 , soto200 , soto100 , soto50 , soto20 , soto10 );
            cout << "Cap nhat thanh cong! Nhan 0 de quay lai : ";
            cin >> quaylai;
            if ( quaylai == 0 ) start();
        }
    }
}

void start(){
    system("cls");
    cout << "WELCOME" << endl;
    cout << "1. Dang nhap" << endl;
    cout << "2. Dang ky" << endl;
    cout << "3. Kiem tra trang thai the" << endl;
    cout << "4. Kiem tra may ATM" << endl;
    cout << "5. Them tien vao may ATM" << endl;
    cout << "6. Thoat" << endl;
    cout << "Vui long lua chon dich vu : " ;
    int n;
    cin>>n;
    system("cls");
    switch(n){
    case 1 :  {
        cout << "DANG NHAP" << endl;
        dangnhap();
        break;
    }
    case 2 : {
        cout << "DANG KY TAI KHOAN" << endl;
        cout << "Luu y:" <<endl
            << "1. Doi voi tai khoan : Chua tu 8 den 12 ky tu, chi bao gom chu thuong (khong dau) hoac so; khong bao gom chu in hoa va ky tu dac biet. " << endl
            << "2. Doi voi mat khau : Chua tu 8 den 16 ky tu, khong bao gom dau cach." << endl;
        dangky();
        break;
    }
    case 3 : {
        cout << "Nhap ten tai khoan : ";
        string id;
        cin>>id;
        if ( kiem_tra_trang_thai_the( id ) == 1 ) {
            cout << "The cua ban van dang duoc luu hanh!" << endl;
        } else {
            if ( kiem_tra_trang_thai_the( id ) == -1 ) cout << "The cua ban da bi khoa tam thoi!" << endl; else {
                cout << "The cua ban khong ton tai!" << endl;
            }
        }
        cout << "Nhap 0 de quay lai : " ;
        int re;
        cin>>re;
        if ( re == 0 ) start();
        break;
    }
    case 4 : {
    kiem_tra_atm();
    break;
    }
    case 5 : {
    them_tien_vao_may();
    break;
    }
    case 6 : {
        cout << "~GOOD BYE~";
        exit(0);
        break;
    }
    }
}

void gui_tien( string id ) {
    cout << "Vui long nhap so luong cac menh gia! Luu y so luong cua tung menh gia phai la mot so nguyen lon hon hoac bang 0." << endl;
    cout << "1. 500.000 VND : ";
    int soto500,soto200,soto100,soto50,soto20,soto10;
    cin >> soto500;
    while ( soto500 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "1. 500.000 VND : ";
        cin >> soto500;
    }
    cout << "2. 200.000 VND : ";
    cin >> soto200;
    while ( soto200 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "2. 200.000 VND : ";
        cin >> soto200;
    }
    cout << "3. 100.000 VND : ";
    cin >> soto100;
    while ( soto100 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "3. 100.000 VND : ";
        cin >> soto100;
    }
    cout << "4. 50.000 VND : ";
    cin >> soto50;
    while ( soto50 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "4. 50.000 VND : ";
        cin >> soto50;
    }
    cout << "5. 20.000 VND : ";
    cin >> soto20;
    while ( soto20 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "5. 20.000 VND : ";
        cin >> soto20;
    }
    cout << "6. 10.000 VND : ";
    cin >> soto10;
    while ( soto10 < 0 ) {
        cout << "So luong khong hop le! Vui long nhap lai."<<endl;
        cout << "6. 10.000 VND : ";
        cin >> soto10;
    }
    long int sum;
    sum = soto500*500000+soto200*200000+soto100*100000+soto50*50000+soto20*20000+soto10*10000;
    if ( sum == 0 ) {
        cout << "Gui tien khong hop le! Nhan 0 de quay lai : ";
        int quaylai;
        cin >> quaylai;
        if ( quaylai == 0 ) menu( id );
    }
    cout << "De xac nhan gui "<< sum <<" VND vao ngan hang, vui long nhap mat khau cua ban : ";
    string re;
    re = nhap_mat_khau();
    while ( re != lay_ra_pass( id ) ) {
        cout << "Mat khau khong dung! Vui long nhap lai : ";
        re = nhap_mat_khau();
    }
    if ( re == lay_ra_pass( id ) ){
        string money = lay_ra_money( id ),newmoney;
        int tien;
        istringstream( money ) >> tien;
        tien += sum;
        newmoney = to_string( tien );
        changemoney( id , newmoney );
        thay_doi_ngan_hang( sum , soto500 , soto200 , soto100 , soto50 , soto20 , soto10 );
        lsdd_guitien( id , to_string( sum ) , newmoney );
        cout << "Ban da gui tien thanh cong! Nhan 0 de quay lai : ";
        cin >> re;
        if ( re == "0" ) menu( id );
    }
}

void doi_mat_khau( string id ) {
    cout << "Nhap mat khau hien tai : " ;
    string pass1;
    pass1 = nhap_mat_khau();
    while ( pass1 != lay_ra_pass( id ) ) {
        cout << "Mat khau khong dung! Vui long nhap lai." << endl;
        cout << "Nhap mat khau hien tai : ";
        pass1 = nhap_mat_khau();
    }
    cout << "Nhap mat khau moi : " ;
    string newpass;
    newpass = nhap_mat_khau();
    while ( kiem_tra_password( newpass ) == false ) {
        cout << "Mat khau khong hop le! Vui long nhap lai." << endl;
        cout << "Nhap mat khau moi : ";
        newpass = nhap_mat_khau();
    }
    while ( newpass == pass1 ) {
        cout << "Mat khau moi trung voi mat khau hien tai! Vui long nhap lai." << endl;
        cout << "Nhap mat khau moi : ";
        newpass = nhap_mat_khau();
    }
    changepass( id , newpass );
    cout << "Ban da doi mat khau thanh cong! Vui long nhan 0 de quay lai : ";
    int re;
    cin>>re;
    if ( re == 0 ) menu( id );
}

void rut_tien( string id ) {
    ifstream f( "nganhang.txt" );
    long int tien;
    int to500,to200,to100,to50,to20,to10;
    if ( f.is_open() ) {
        f >> tien >> to500 >> to200 >> to100 >> to50 >> to20 >> to10;
        int sotiennhonhat = 0;
        if ( to10 > 0 ) sotiennhonhat = 10000; else
        if ( to20 > 0 ) sotiennhonhat = 20000; else
        if ( to50 > 0 ) sotiennhonhat = 50000; else
        if ( to100 > 0 ) sotiennhonhat = 100000; else
        if ( to200 > 0 ) sotiennhonhat = 200000; else
        if ( to500 > 0 ) sotiennhonhat = 500000;
        cout <<"Luu y : so tien ban muon rut phai la boi so cua " << sotiennhonhat << " VND" << endl;
        cout <<"Nhap so tien : " ;
        long int tienrut,maxx;
        istringstream( lay_ra_money( id ) ) >> maxx;
        cin >> tienrut;
        while ( tienrut > maxx ) {
            cout << "So du khong du! Vui long nhap lai." <<endl;
            cout << "Nhap so tien : ";
            cin >> tienrut;
        }
        while ( tienrut % sotiennhonhat != 0 || tienrut == 0 ) {
            cout << "So tien khong phai la boi so cua " << sotiennhonhat << " VND! Vui long nhap lai." << endl;
            cout << "Nhap so tien : " ;
            cin >> tienrut;
        }
        long int tienrut1 = tienrut;
        int ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        int f[6];
        f[0] = start_from_500( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        f[1] = start_from_200( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        f[2] = start_from_100( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        f[3] = start_from_50( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        f[4] = start_from_20( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        f[5] = start_from_10( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
        int cachlaymax = -1;ra500 = 0, ra200 = 0, ra100 = 0, ra50 = 0, ra20 = 0, ra10 = 0;
        for ( int i = 0 ; i < 6 ; i++ ) {
            if ( f[i] > cachlaymax ) cachlaymax = f[i];
        }
        if ( cachlaymax == -1 ) {
            cout << "May khong du tien de dap ung so tien cua ban!" << endl;
        } else {
            int cachlay = cachlaymax;
            int j = 0;
            for ( int i = 0 ; i < 6 ; i++ ) {
                if ( f[i] > 0 && f[i] <= cachlay ) {
                    j = i;
                    cachlay = f[i];
                }
            }
            switch( j ) {
            case 0 : {
            f[0] = start_from_500( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            case 1 : {
            f[1] = start_from_200( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            case 2 : {
            f[2] = start_from_100( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            case 3 : {
            f[3] = start_from_50( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            case 4 : {
            f[4] = start_from_20( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            case 5 : {
            f[5] = start_from_10( tienrut , to500 , to200 , to100 , to50 , to20 , to10 , ra500 , ra200 , ra100 , ra50 , ra20 , ra10 );
            break;
            }
            }
            cout << "De xac nhan rut " << tienrut1 << " VND, vui long nhap lai mat khau : " ;
            string pass;
            pass = nhap_mat_khau();
            while ( pass != lay_ra_pass( id ) ) {
                cout << "Mat khau khong dung! Vui long nhap lai : " ;
                pass = nhap_mat_khau();
            }
            cout << "Rut tien thanh cong! So tien ban nhan duoc la : " << endl;
            if ( ra500 != 0 ) cout << "500000 VND : " << ra500 << " to." <<endl;
            if ( ra200 != 0 ) cout << "200000 VND : " << ra200 << " to." <<endl;
            if ( ra100 != 0 ) cout << "100000 VND : " << ra100 << " to." <<endl;
            if ( ra50 != 0 ) cout << "50000 VND : " << ra50 << " to." <<endl;
            if ( ra20 != 0 ) cout << "20000 VND : " << ra20 << " to." <<endl;
            if ( ra10 != 0 ) cout << "10000 VND : " << ra10 << " to." <<endl;
            thay_doi_ngan_hang( -1*tienrut , -1*ra500 , -1*ra200 , -1*ra100 , -1*ra50 , -1*ra20 , -1*ra10 );
            long int conlai = maxx - tienrut;
            string newmoney = to_string( conlai );
            changemoney( id , newmoney );
            lsdd_ruttien( id , to_string( tienrut ) , newmoney );
        }
        cout << "Nhan 0 de quay lai : ";
        int re;
        cin >> re;
        if ( re == 0 ) menu( id );
    }
}

void chuyen_tien( string id ) {
    cout << "Luu y : So tien chuyen toi thieu la 50000 VND , toi da la 10000000 VND / 1 lan!" << endl;
    cout << "Nhap tai khoan nguoi nhan : ";
    string id1;
    cin >> id1;
    while ( kiem_tra_id( id1 ) != 0 ) {
        cout << "Tai khoan khong hop le! Vui long nhap lai : ";
        cin >> id1;
    }
    long int maxx;
    istringstream( lay_ra_money( id ) ) >> maxx;
    long int tienchuyen;
    cout << "Nhap so tien can chuyen : ";
    cin >> tienchuyen;
    while ( tienchuyen < 50000 )  {
        cout << "So tien toi thieu ban can chuyen la 50000 VND! Vui long nhap lai." << endl;
        cout << "Nhap so tien can chuyen : ";
        cin >> tienchuyen;
    }
    while ( tienchuyen > 10000000 ) {
        cout << "So tien toi da ban co the chuyen la 10000000 VND/ 1 ngay! Vui long nhap lai." << endl;
        cout << "Nhap so tien can chuyen : ";
        cin >> tienchuyen;
    }
    while ( tienchuyen > maxx ) {
        cout << "So du cua ban khong du! Vui long nhap lai." << endl;
        cout << "Nhap so tien can chuyen : ";
        cin >> tienchuyen;
    }
    cout << "Nhap lai mat khau : ";
    string checkpass;
    checkpass = nhap_mat_khau();
    while ( checkpass != lay_ra_pass( id ) ) {
        cout << "Mat khau khong dung! Vui long nhap lai." << endl;
        cout << "Nhap lai mat khau : ";
        checkpass = nhap_mat_khau();
    }
    maxx -= tienchuyen;
    string conlai = to_string ( maxx );
    changemoney ( id , conlai );
    long int goc ;
    istringstream( lay_ra_money( id1 ) ) >> goc;
    goc += tienchuyen;
    string tienmoi = to_string ( goc );
    changemoney ( id1 , tienmoi );
    lsdd_chuyentien( id , to_string( tienchuyen ) , conlai , id1 );
    lsdd_nhantien( id1 , to_string( tienchuyen ) , tienmoi , id );
    cout << "Chuyen tien thanh cong! Nhan 0 de quay lai : " ;
    int re;
    cin >> re;
    if ( re == 0 ) menu( id );
}

void lay_ra_lich_su_giao_dich( string id ) {
    string s;
    int dem = 0;
    int stt = lay_ra_stt ( id );
    ifstream f( "lichsugiaodich.txt" );
    if ( f.is_open() ) {
            while ( !f.eof() ){
            getline( f , s);
            if ( s == "-----" ) dem++;
            if ( dem == stt ) {
                getline( f , s );
                while ( s != "-----" ) {
                    cout << s << endl;
                    getline( f , s );
                }
                break;
            }
        }
    }
    f.close();
    cout <<"Nhan 0 de quay lai : ";
    int re;
    cin >> re;
    if ( re == 0 ) menu( id );
}

void menu( string id ) {
    system("cls");
    cout << "Xin chao " << id << "!" << endl;
    cout << "1. Gui tien" << endl
             << "2. Rut tien" << endl
             << "3. Chuyen tien" << endl
             << "4. Doi mat khau" << endl
             << "5. Kiem tra so du" << endl
             << "6. Xem lai lich su giao dich" << endl
             << "7. Dang xuat" << endl
             << "Vui long lua chon dich vu : ";
    int n;
    cin >> n;
    switch( n ) {
    case 1 : {
        system( "cls" );
        cout << "GUI TIEN" << endl;
        gui_tien( id );
        break;
    }
    case 2 : {
        system( "cls" );
        cout << "RUT TIEN" << endl;
        rut_tien( id );
        break;
    }
    case 3 : {
    system( "cls" );
    cout << "CHUYEN TIEN" << endl;
    chuyen_tien ( id );
    break;
    }
    case 4 : {
        system( "cls" );
        cout << "DOI MAT KHAU" << endl;
        doi_mat_khau( id );
        break;
    }
    case 5 : {
        system( "cls" );
        cout << "Tai khoan cua ban con : " << lay_ra_money( id ) << " VND" <<endl;
        cout << "Nhan 0 de quay lai : " ;
        int re;
        cin >> re;
        if ( re == 0 ) menu( id );
        break;
    }
    case 6 : {
        system( "cls" );
        cout << "LICH SU GIAO DICH" << endl;
        lay_ra_lich_su_giao_dich( id );
        break;
    }
    case 7 : {
    start();
    break;
    }
    }
}
