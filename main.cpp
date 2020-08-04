#include <iostream>
#include <bitset>
#include <stdint.h>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;

int *mas_tab;// = new int[];
//int *oct1, *oct2, *oct3, *oct4;
int ot1, ot2, ot3, ot4;
int broad4;


/*string change_int_to_string(int start,int done, string stri, int tab[])
{
    for(int i=start;i<done;i++)
        stri.push_back('0'+tab[i]);
    return stri;
}
int bin_to_dec(string stri)
{
    int bin = strtol(stri.c_str(),NULL,2);
    return bin;
}*/




void maska(int x)
{
    //int mas[32];
    mas_tab = new int[32];
    cout<<"\nmaska to "<<x <<endl;
    for(int i =0; i<32;i++){
        for(int j=0;j<x;j++){
            mas_tab[j]=1;}

    mas_tab[i]=0;
    }
   cout<<"\nmaska to: "<<endl;
    for(int i=0;i<32;i++){
        if(i==8)
            cout<<".";
        else if(i==16)
            cout<<".";
        else if(i==24)
            cout<<".";
        cout<<mas_tab[i];
    }
       cout<<endl;
}

void adres_sieci(int dec_tab[], int x)
{

    uint32_t ip = dec_tab[0] << 24u | dec_tab[1] <<16u | dec_tab[2] << 8u | dec_tab[3];
    string adrIP = bitset<32>(ip).to_string();
    //cout<<bitset<8>(dec_tab[0])<<endl;
    //cout<<"binarnie: "<<bitset<32>(ip)<<endl;
    //cout<<adrIP<<endl;
    int bin_tab[31];
    for(int i =0; i<32;i++){
        bin_tab[i]=adrIP[i]-'0';
    }
    for(int j=0;j<32;j++)
        {
        if(j==8)
            cout<<".";
        else if(j==16)
            cout<<".";
        else if(j==24)
            cout<<".";
        cout<<bin_tab[j];
        }
    maska(x);
    int net_adr[31];
    // mnozenie adres sieci!!!
    for(int i = 0; i<32;i++)
        {
        cout<<*mas_tab;
        net_adr[i]=bin_tab[i]*(*mas_tab);
        mas_tab++;
        }
        cout<<endl;

    for(int j=0;j<32;j++)
        {
        if(j==8)
            cout<<".";
        else if(j==16)
            cout<<".";
        else if(j==24)
            cout<<".";
        cout<<net_adr[j];
        }

    string octet1;
    for(int i=0;i<8;i++)
        octet1.push_back('0'+net_adr[i]);
    //octet1=change_int_to_string(0,8,octet1,net_adr);

    cout<<"\noktet 1: "<<octet1<<endl;
    /*int*/ ot1 = strtol(octet1.c_str(),NULL,2);
    //bin_to_dec(octet1);
    cout<<"\noktet 1 w dzisietnym: "<<ot1<<endl;

    string octet2;
    for(int i=8;i<16;i++)
    octet2.push_back('0'+net_adr[i]);

    cout<<"\noktet 2: "<<octet2<<endl;
    /*int*/ ot2 = strtol(octet2.c_str(),NULL,2);
    cout<<"\noktet 2 w dzisietnym: "<<ot2<<endl;

    string octet3;
    for(int i=16;i<24;i++)
    octet3.push_back('0'+net_adr[i]);

    cout<<"\noktet 3: "<<octet3<<endl;
    /*int*/ ot3 = strtol(octet3.c_str(),NULL,2);
    cout<<"\noktet 3 w dzisietnym: "<<ot3<<endl;

    string octet4;
    for(int i=24;i<32;i++)
    octet4.push_back('0'+net_adr[i]);

    cout<<"\noktet 4: "<<octet4<<endl;
    /*int*/ ot4 = strtol(octet4.c_str(),NULL,2);
    cout<<"\noktet 4 w dzisietnym: "<<ot4<<endl;


    cout<<"adres sieci: "<<ot1<<"."<<ot2<<"."<<ot3<<"."<<ot4<<endl;
}

void adres_broadcast()
{
    int broad[32];
    //cout<<"f()adres_broadcast"<<endl;
    //zerujemy licznik
    for(int i = 0; i<32;i++)
        {
        mas_tab--;
        }
    // tworzymy tablice adresu rozg³oszeniowego
    for(int i = 0;i<32;i++)
    {
        broad[i]=*mas_tab;
        mas_tab++;
    }
    //operacja NOT na masce by obliczyc adres rozg³oszeniowy
    for(int i = 0;i<32;i++)
    {
        //cout<<broad[i];
        if(broad[i]==0)
            broad[i]=1;
        else if(broad[i]==1)
            broad[i]=0;
    }
    cout<<endl;

    /*for(int i=0;i<32;i++)
        {
        if(i==8)
            cout<<".";
        else if(i==16)
            cout<<".";
        else if(i==24)
            cout<<".";
        cout<<broad[i];
        }*/

    string octet1;
    for(int i=0;i<8;i++)
        octet1.push_back('0'+broad[i]);
    //octet1=change_int_to_string(0,8,octet1,net_adr);

    //cout<<"\noktet 1: "<<octet1<<endl;
    int oct1 = strtol(octet1.c_str(),NULL,2);
    //bin_to_dec(octet1);
    //cout<<"\noktet 1 w dzisietnym: "<<oct1<<endl;

    string octet2;
    for(int i=8;i<16;i++)
    octet2.push_back('0'+broad[i]);

    //cout<<"\noktet 2: "<<octet2<<endl;
    int oct2 = strtol(octet2.c_str(),NULL,2);
    //cout<<"\noktet 2 w dzisietnym: "<<oct2<<endl;

    string octet3;
    for(int i=16;i<24;i++)
    octet3.push_back('0'+broad[i]);

    //cout<<"\noktet 3: "<<octet3<<endl;
    int oct3 = strtol(octet3.c_str(),NULL,2);
    //cout<<"\noktet 3 w dzisietnym: "<<oct3<<endl;

    string octet4;
    for(int i=24;i<32;i++)
    octet4.push_back('0'+broad[i]);

    //cout<<"\noktet 4: "<<octet4<<endl;
    int oct4 = strtol(octet4.c_str(),NULL,2);
    //cout<<"\noktet 4 w dzisietnym: "<<oct4<<endl;
    broad4=oct4+ot4;

    //cout<<"adres rozgloszeniowy1: "<<oct1<<"."<<oct2<<"."<<oct3<<"."<<oct4<<endl;
    cout<<"adres rozgloszeniowy prawdziwy: "<<oct1+ot1<<"."<<oct2+ot2<<"."<<oct3+ot3<<"."<<broad4<<endl;



    delete mas_tab;

}
void klasa_IP(int octet1)
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    char d = 'D';
    char e = 'E';
    //cout<<"\n"<<octet1<<endl;
    string klasIP = bitset<8>(octet1).to_string();
    cout<<endl;
    if(klasIP[0]=='0')
        cout<<"Klasa adresu: "<<a<<endl;
    else if(klasIP[0]=='1' && klasIP[1]=='0')
        cout<<"Klasa adresu: "<<b<<endl;
    else if(klasIP[0]=='1' && klasIP[1]=='1' && klasIP[2]=='0')
        cout<<"Klasa adresu: "<<c<<endl;
    else if(klasIP[0]=='1' && klasIP[1]=='1' && klasIP[2]=='1' && klasIP[3]=='0')
        cout<<"Klasa adresu: "<<d<<endl;
    else if(klasIP[0]=='1' && klasIP[1]=='1' && klasIP[2]=='1' && klasIP[3]=='1')
        cout<<"Klasa adresu: "<<e<<endl;
}

void adres_1st_host()
{
    cout<<"Adres pierwszego hosta: ";
    cout<<ot1<<"."<<ot2<<"."<<ot3<<"."<<ot4+1<<endl;
}
void adres_last_host()
{
    cout<<"Adres ostatniego hosta: ";
    cout<<"adres sieci: "<<ot1<<"."<<ot2<<"."<<ot3<<"."<<broad4-1<<endl;
}

void host_number(int x)
{
    int h_num = pow(2,(32-x))-2;
    cout<<"Liczba hostow: "<<h_num<<endl;

}

int main()
{
    int decIp[4];
    int x;
    cout<<"Podaj adres IP rozdzielajac okrety spacja: "<<endl;
    cin>> decIp[0] >> decIp[1] >> decIp[2] >> decIp[3];
    cout<<"Podaj maske sieci: "<<endl;
    cin>>x;
    while(x<0 || x>32){
        cout<<"Podana jest zla liczba, musi byc od 0-32 \nPodaj jeszcze raz: "<<endl;
        cin>>x;
    }
    adres_sieci(decIp, x);
    klasa_IP(decIp[0]);
    adres_broadcast();
    adres_1st_host();
    adres_last_host();
    host_number(x);



    return 0;
}

