#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include <iomanip> 
typedef struct node
{
        int year,weight,sanum;
        char first[40],last[40],phonenum[10];
        struct node *next;
}Node;
using namespace std;
int main()
{
    int pnum,num,p,cho,search_num,correct,delt[40],delete_num,sn,dnum,edit_num,cohsort,i,ednum;
    int Fsort[100][100],Lsort[100][100],pnsort[100][100],ysort[100][100],wsort[100][100];
    int may=0,miy=1000,avy=0,maw=0,miw=1000,avw=0;
    char search_last[40],delete_last[40],edit_last[40];
    ifstream fin("int.txt");
    ofstream fcout("output.txt");
    fin>>pnum; 
    Node *temp,*sat,*sa,*stemp;
    sa=(Node *)malloc(sizeof(Node));
    num=0;
    while(num!=pnum)
    {
        fin>>sa->first;
        fin>>sa->last;
        fin>>sa->phonenum;
        fin>>sa->year;
        fin>>sa->weight;
        sa->sanum=num;
        if(sa->year>may)
            may=sa->year;
        if(sa->year<miy)
            miy=sa->year;
        if(sa->weight>maw)
            maw=sa->weight;
        if(sa->weight<miw)
            miw=sa->weight;
        avy+=sa->year;
        avw+=sa->weight;
        num+=1;
        temp=(Node *)malloc(sizeof(Node));
        temp->next=sa;
        sa=temp;
    }
    sat=sa->next;
    cout<<"Welcome to use Contact Book"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
    cout<<"What do you want to do?";
    do
    {
                cin>>cho;
                cout<<endl;
    switch(cho)
    {
        case 1:
             system("CLS");
             cout<<"Please input last name who you want to search :";
             cin>>search_last;
             cout<<endl;
             search_num=pnum;
             sa=sat;
             stemp=sat;
             sn=0;
             while(search_num!=0)
             {
                 p=0;
                 correct=1;
                 while(search_last[p]!='\0')
                 {
                     if(search_last[p]!=sa->last[p])
                         correct=0;
                         p++;
                 }
                 if(correct==1)
                 {
                     sn+=1;
                     cout<<sa->first<<" ";
                     cout<<sa->last<<" ";
                     cout<<sa->phonenum<<" ";
                     cout<<sa->year<<" ";
                     cout<<sa->weight<<" ";
                     cout<<endl;
                 }
                 search_num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             if(sn==0)
                 cout<<"no information"<<endl<<endl;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 2:
             system("CLS");
             sa=temp;
             cout<<"Please input first name :";
             cin>>sa->first;
             cout<<"Please input last name :";
             cin>>sa->last;
             cout<<"Please input Phone number :";
             cin>>sa->phonenum;
             cout<<"Please input years :";
             cin>>sa->year;
             cout<<"Please input weight :";
             cin>>sa->weight;
             if(sa->year>may)
                may=sa->year;
             if(sa->year<miy)
                miy=sa->year;
             if(sa->weight>maw)
                maw=sa->weight;
             if(sa->weight<miw)
                miw=sa->weight;
             avy+=sa->year;
             avw+=sa->weight;
             pnum+=1;
             sa->sanum=pnum-1;
             temp=(Node *)malloc(sizeof(Node));
             temp->next=sa;
             sa=temp;
             sat=sa->next;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 3:
             system("CLS");
             cout<<"Please input last name who you want to delete :";
             cin>>delete_last;
             cout<<endl;
             delete_num=pnum;
             sa=sat;
             stemp=sat;
             sn=0;
             dnum=0;
             while(delete_num!=0)
             {
                 p=0;
                 correct=1;
                 while(delete_last[p]!='\0')
                 {
                     if(delete_last[p]!=sa->last[p])
                         correct=0;
                         p++;
                 }
                 if(correct==1)
                 {
                     sn++;
                     cout<<sn<<". ";
                     cout<<setw(12)<<sa->first<<" ";
                     cout<<setw(12)<<sa->last<<" ";
                     cout<<endl;
                     delt[sn]=sa->sanum;
                 }
                 delete_num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             if(sn!=0)
             {
                 cout<<"Please choose number who you what to delete: ";
                 cin>>dnum;
                 sa=sat;
                 stemp=sat;
                 if(delt[dnum]!=pnum-1)
                 {
                     while(sa->sanum!=delt[dnum]+1)
                     {
                         sa->sanum-=1;
                         stemp=stemp->next;
                         sa=stemp;
                     }
                     sa->sanum-=1;
                     sa->next=sa->next->next;
                 }
                 else
                 {
                     sa=sa->next;
                     sat=sa;
                 }
                 pnum-=1;
                 sa=sat;
                 stemp=sat;             
                 num=pnum;
                 may=0;miy=1000;avy=0;maw=0;miw=1000;avw=0;
                 while(num!=0)
                 {
                     if(sa->year>may)
                         may=sa->year;
                     if(sa->year<miy)
                         miy=sa->year;
                     if(sa->weight>maw)
                         maw=sa->weight;
                     if(sa->weight<miw)
                         miw=sa->weight;
                     avy+=sa->year;
                     avw+=sa->weight;
                     num-=1;
                     stemp=stemp->next;
                     sa=stemp;
                 }
             }
             else
                 cout<<"no information"<<endl;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 4:
             system("CLS");
             cout<<"Please input last name who you want to edit :";
             cin>>edit_last;
             cout<<endl;
             edit_num=pnum;
             sa=sat;
             stemp=sat;
             sn=0;
             dnum=0;
             while(edit_num!=0)
             {
                 p=0;
                 correct=1;
                 while(edit_last[p]!='\0')
                 {
                     if(edit_last[p]!=sa->last[p])
                         correct=0;
                         p++;
                 }
                 if(correct==1)
                 {
                     sn++;
                     cout<<sn<<". ";
                     cout<<setw(12)<<sa->first<<" ";
                     cout<<setw(12)<<sa->last<<" ";
                     cout<<setw(15)<<sa->phonenum;
                     cout<<setw(5)<<sa->year;
                     cout<<setw(5)<<sa->weight;
                     cout<<endl;
                     delt[sn]=sa->sanum;
                 }
                 edit_num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             if(sn!=0)
             {
                 cout<<"Please choose number who you what to edit: ";
                 cin>>dnum;
                 cout<<endl;
                 cout<<"Which do you want to edit?"<<endl;
                 cout<<"1.first neme  2.last name  3.phone number  4.year  5.weight";
                 cin>>ednum;  
                 sa=sat;
                 stemp=sat;
                 while(sa->sanum!=delt[dnum]+1)
                 {
                     stemp=stemp->next;
                     sa=stemp;
                 }
                 stemp=stemp->next;
                 sa=stemp;
                 switch(ednum)
                 {
                     case 1:
                          cout<<"Please input first name :";
                          cin>>sa->first;
                     break;
                     case 2:
                          cout<<"Please input last name :";
                          cin>>sa->last;
                     break;
                     case 3:
                          cout<<"Please input Phone number :";
                          cin>>sa->phonenum;
                     break;
                     case 4:
                          cout<<"Please input years :";
                          cin>>sa->year;
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          may=0;miy=1000;avy=0;
                          while(num!=0)
                          {
                              if(sa->year>may)
                                  may=sa->year;
                              if(sa->year<miy)
                                  miy=sa->year;
                              avy+=sa->year;
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                     break;
                     case 5:
                          cout<<"Please input weight :";
                          cin>>sa->weight;
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          maw=0;miw=1000;avw=0;
                          while(num!=0)
                          {
                              if(sa->weight>maw)
                                  maw=sa->weight;
                              if(sa->weight<miw)
                                  miw=sa->weight;
                              avw+=sa->weight;
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                     break;
                 }
             }
             else
                 cout<<"no information"<<endl;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 5:
             system("CLS");
             sa=sat;
             fcout<<pnum<<endl;
             num=pnum;
             while(num!=0)
             {
                 temp=temp->next;
                 sa=temp;
                 fcout<<sa->first<<" ";
                 fcout<<sa->last<<" ";
                 fcout<<sa->phonenum<<" ";
                 fcout<<sa->year<<" ";
                 fcout<<sa->weight<<" ";
                 fcout<<sa->sanum;
                 fcout<<endl;
                 num-=1;
             }
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 6:
             system("CLS");
             sa=sat;
             stemp=sat;             
             num=pnum;
             while(num!=0)
             {
                 cout<<setw(12)<<sa->first ;
                 cout<<setw(12)<<sa->last;
                 cout<<setw(15)<<sa->phonenum;
                 cout<<setw(5)<<sa->year;
                 cout<<setw(5)<<sa->weight;
                 cout<<setw(5)<<sa->sanum;
                 cout<<endl;
                 num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 7:
             system("CLS");
             cout<<"1. First name  2.Last name  3.phone number  4.Year  5.Weight"<<endl;
             cout<<"Please choose number which attribute you what to sort: ";
             cin>>cohsort;
             switch(cohsort)
             {
                 case 1:
                      for(i=0;i<25;i++)
                      {
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          while(num!=0)
                          {
                              if(sa->first[0]==i+'A')
                              {
                                  cout<<left<<setw(12)<<sa->first ;
                                  cout<<left<<setw(12)<<sa->last;
                                  cout<<left<<setw(15)<<sa->phonenum;
                                  cout<<left<<setw(5)<<sa->year;
                                  cout<<left<<setw(5)<<sa->weight;
                                  cout<<left<<sa->sanum;
                                  cout<<left<<endl;
                              }
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                      }
                  break;
                  case 2:
                      for(i=0;i<25;i++)
                      {
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          while(num!=0)
                          {
                              if(sa->last[0]==i+'A')
                              {
                                  cout<<left<<setw(12)<<sa->first ;
                                  cout<<left<<setw(12)<<sa->last;
                                  cout<<left<<setw(15)<<sa->phonenum;
                                  cout<<left<<setw(5)<<sa->year;
                                  cout<<left<<setw(5)<<sa->weight;
                                  cout<<left<<sa->sanum;
                                  cout<<left<<endl;
                              }
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                      }
                  break;
                  case 3:
                      for(i=0;i<99;i++)
                      {
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          while(num!=0)
                          {
                              if(((sa->phonenum[2]-'0')*10+sa->phonenum[3]-'0')==i)
                              {
                                  cout<<left<<setw(12)<<sa->first ;
                                  cout<<left<<setw(12)<<sa->last;
                                  cout<<left<<setw(15)<<sa->phonenum;
                                  cout<<left<<setw(5)<<sa->year;
                                  cout<<left<<setw(5)<<sa->weight;
                                  cout<<left<<sa->sanum;
                                  cout<<left<<endl;
                              }
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                      }
                  break;
                  case 4:
                      for(i=0;i<99;i++)
                      {
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          while(num!=0)
                          {
                              if(sa->year==i)
                              {
                                  cout<<left<<setw(12)<<sa->first ;
                                  cout<<left<<setw(12)<<sa->last;
                                  cout<<left<<setw(15)<<sa->phonenum;
                                  cout<<left<<setw(5)<<sa->year;
                                  cout<<left<<setw(5)<<sa->weight;
                                  cout<<left<<sa->sanum;
                                  cout<<left<<endl;
                              }
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                      }
                  case 5:
                      for(i=0;i<99;i++)
                      {
                          sa=sat;
                          stemp=sat;             
                          num=pnum;
                          while(num!=0)
                          {
                              if(sa->weight==i)
                              {
                                  cout<<left<<left<<setw(12)<<sa->first ;
                                  cout<<left<<setw(12)<<sa->last;
                                  cout<<left<<setw(15)<<sa->phonenum;
                                  cout<<left<<setw(5)<<sa->year;
                                  cout<<left<<setw(5)<<sa->weight;
                                  cout<<left<<sa->sanum;
                                  cout<<left<<endl;
                              }
                              num-=1;
                              stemp=stemp->next;
                              sa=stemp;
                          }
                      }
                  break;
             }
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 8:
             system("CLS");
             cout<<"======================================"<<endl;
             cout<<"Max of years is "<<may<<endl;
             cout<<"======================================"<<endl<<endl;
             cout<<"======================================"<<endl;
             cout<<"ALL friends of Max years:"<<endl;
             sa=sat;
             stemp=sat;             
             num=pnum;
             while(num!=0)
             {
                 if(sa->year==may)
                 {
                     cout<<left<<left<<setw(12)<<sa->first ;
                     cout<<left<<setw(12)<<sa->last;
                     cout<<left<<setw(15)<<sa->phonenum;
                     cout<<left<<setw(5)<<sa->year;
                     cout<<left<<setw(5)<<sa->weight;
                     cout<<left<<sa->sanum;
                     cout<<left<<endl;
                 }
                 num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             cout<<"======================================"<<endl;
             cout<<endl;
             cout<<"======================================"<<endl;
             cout<<"Min of years is "<<miy<<endl;
             cout<<"======================================"<<endl<<endl;
             cout<<"======================================"<<endl;
             cout<<"ALL friends of Min years:"<<endl;
             sa=sat;
             stemp=sat;             
             num=pnum;
             while(num!=0)
             {
                 if(sa->year==miy)
                 {
                     cout<<left<<left<<setw(12)<<sa->first ;
                     cout<<left<<setw(12)<<sa->last;
                     cout<<left<<setw(15)<<sa->phonenum;
                     cout<<left<<setw(5)<<sa->year;
                     cout<<left<<setw(5)<<sa->weight;
                     cout<<left<<sa->sanum;
                     cout<<left<<endl;
                 }
                 num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             cout<<endl;
             cout<<"======================================"<<endl;
             cout<<"======================================"<<endl;
             cout<<"Average of years is "<<(float)avy/pnum<<endl;
            cout<<"======================================"<<endl;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        case 9:
             system("CLS");
             cout<<"======================================"<<endl;
             cout<<"Max of weights is "<<maw<<endl;
             cout<<"======================================"<<endl<<endl;
             cout<<"======================================"<<endl;
             cout<<"ALL friends of Max weights:"<<endl;
             sa=sat;
             stemp=sat;             
             num=pnum;
             while(num!=0)
             {
                 if(sa->weight==maw)
                 {
                     cout<<left<<left<<setw(12)<<sa->first ;
                     cout<<left<<setw(12)<<sa->last;
                     cout<<left<<setw(15)<<sa->phonenum;
                     cout<<left<<setw(5)<<sa->year;
                     cout<<left<<setw(5)<<sa->weight;
                     cout<<left<<sa->sanum;
                     cout<<left<<endl;
                 }
                 num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             cout<<"======================================"<<endl;
             cout<<endl;
             cout<<"======================================"<<endl;
             cout<<"Min of weights is "<<miw<<endl;
             cout<<"======================================"<<endl<<endl;
             cout<<"======================================"<<endl;
             cout<<"ALL friends of Min weights:"<<endl;
             sa=sat;
             stemp=sat;             
             num=pnum;
             while(num!=0)
             {
                 if(sa->weight==miw)
                 {
                     cout<<left<<left<<setw(12)<<sa->first ;
                     cout<<left<<setw(12)<<sa->last;
                     cout<<left<<setw(15)<<sa->phonenum;
                     cout<<left<<setw(5)<<sa->year;
                     cout<<left<<setw(5)<<sa->weight;
                     cout<<left<<sa->sanum;
                     cout<<left<<endl;
                 }
                 num-=1;
                 stemp=stemp->next;
                 sa=stemp;
             }
             cout<<"======================================"<<endl;
             cout<<endl;
             cout<<"======================================"<<endl;
             cout<<"Average of weights is "<<(float)avw/pnum<<endl;
             cout<<"======================================"<<endl;
             cout<<endl;
             cout<<"1.Search  2.Insertion  3.Deletion  4.Edit  5.Save  6.Show all friends  7.Sort  8.Extream years  9.Extream weights  10.Exit"<<endl;
             cout<<"What do you want to do?";
             break;
        }       
             
    }while(cho!=10); 
}
