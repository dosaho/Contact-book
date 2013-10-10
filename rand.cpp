#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include <iomanip>
using namespace std;
int main()
{
    int i,b,r,j,namef[20][20],dn;
    char a;
    ofstream fcout("int.txt");
    
    
    cout<<"Please input the numbers of data :";
    cin>>dn;
    fcout<<dn<<endl;
    for(i=0;i<dn;i++)
    {
        r=rand()%11;
        switch(r)
        {
                 case 0:
                      fcout<<"Miller"<<" ";
                      break;
                 case 1:
                      fcout<<"Cook"<<" ";
                      break;
                 case 2:
                      fcout<<"Wood"<<" ";
                      break;
                 case 3:
                      fcout<<"Bird"<<" ";
                      break;
                 case 4:
                      fcout<<"Hand"<<" ";
                      break;
                 case 5:
                      fcout<<"Field"<<" ";
                      break;
                 case 6:
                      fcout<<"Brown"<<" ";
                      break;
                 case 7:
                      fcout<<"Churchill"<<" ";
                      break;
                 case 8:
                      fcout<<"David"<<" ";
                      break;
                 case 9:
                      fcout<<"Smith"<<" ";
                      break;
                 case 10:
                      fcout<<"Kent"<<" ";
                      break;
        }
        r=rand()%15;
        switch(r)
        {
                 case 0:
                      fcout<<"Leslie"<<" ";
                      break;
                 case 1:
                      fcout<<"Leo"<<" ";
                      break;
                 case 2:
                      fcout<<"Matt"<<" ";
                      break;
                 case 3:
                      fcout<<"Oscar"<<" ";
                      break;
                 case 4:
                      fcout<<"Messi"<<" ";
                      break;
                 case 5:
                      fcout<<"Rufus"<<" ";
                      break;
                 case 6:
                      fcout<<"Vivian"<<" ";
                      break;
                 case 7:
                      fcout<<"Terence"<<" ";
                      break;
                 case 8:
                      fcout<<"Antony"<<" ";
                      break;
                 case 9:
                      fcout<<"Bernie"<<" ";
                      break;
                 case 10:
                      fcout<<"Carlton"<<" ";
                      break;
                 case 11:
                      fcout<<"Emlyn"<<" ";
                      break;
                 case 12:
                      fcout<<"Freddie"<<" ";
                      break;
                 case 13:
                      fcout<<"Fred"<<" ";
                      break;
                 case 14:
                      fcout<<"Hugh"<<" ";
                      break;
        }
        
        fcout<<"09";
        for(j=2;j<10;j++)
        {
            b=rand()%10;
            fcout<<b;
        }
        fcout<<" ";
        b=0;
        while(b<15||b>100)
        {
            b=rand()%100;
        }
        fcout<<b;
        fcout<<" ";
        b=0;
        while(b<45||b>120)
        {
            b=rand()%120;
        }
        fcout<<b;
        fcout<<endl;
     }
     system("pause");
}
         
