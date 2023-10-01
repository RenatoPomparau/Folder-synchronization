#include <bits/stdc++.h>
#include "matricea.h"


using namespace std;

int main()
{

    // matrice a(2,2,3),b(2,3,2);
    // matrice c;
    // cout<<c;
    // c=a*b;
    //cout<<c;

    cout<<"1. Quit!"<<endl<<"2. Read Matrix"<<endl<<"3. Display Matrix"<<endl
    <<"4. Adition of two matrix from V[]"<<endl<<"5. Multiplication of two matrix from V[]"<<endl;
    int choice,i=0,nr_col,nr_rand;
    matrice v[101];

    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"You Left Succesfully"<<endl;
            return 0;
        }
        case 2:
        {

            cout<<"Nr. col: ";
            cin>>nr_col;
            cout<<"Nr. rand: ";
            cin>>nr_rand;
            matrice a(0,nr_rand,nr_col);
            cout<<"Matrice numarul: "<<i<<endl;
            cin>>a;
            v[i]=a;
            cout<<"Finished reading the matrix "<<i<<endl;
            i++;
            break;
        }
        case 3:
        {

             for(int j=0;j<i;j++)
              {
                cout<<"Matricea numarul "<<j<<endl;
               cout<<v[j];
             }
            break;
        }
        case 4:
        {
            int l,ll;
            matrice Suma(0,0,0);
            cout<<"Matrix from V[] that must be added: ";
            cin>>l>>ll;
            cout<<"Suma"<<endl;
            Suma=v[l]+v[ll];
            cout<<Suma;
            break;
        }
        case 5:
            {

            int o,oo;
            matrice Produs(0,0,0);
            cout<<"Matrix from V[] that must be multiplied: ";
            cin>>o>>oo;
            cout<<"Produs"<<endl;
            Produs=v[o]*v[oo];
            cout<<Produs;
            break;

        }


    }
    }while(choice!=0);





}
