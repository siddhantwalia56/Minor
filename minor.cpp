#include <iostream>
using namespace std;
int ary[10][10],completed[10], n,cost=0, s1[10], p[20];
void takeInput(void);
void mincost(int);
int least(int);

int main(void)
{
    cout<<"Small City have 7 different places where pattroling is needed:";

const char* arr[100]={"HOSPITAL","BANK","INDUSTRIAL AREA","SCHOOL","Public Park","Public Society","College"};
cout<<"\n 1. HOSPITAL\n 2. BANK\n 3. INDUSTRIAL AREA\n 4. SCHOOL\n 5. PUBLIC PARK\n 6. Public Society\n 7. College\n";
int i1=0,j=1,pos,temp;
cout<<"enter the crime rate for places \n";
for(i1=0;i1<7;i1++)
{
cout<<"\n crime rate of " << arr[i1]<<" ";
cin>>s1[i1];
p[i1]=i1+1;
}
for(i1=0;i1<7;i1++)
{
pos=i1;
for(j=i1+1;j<7;j++)
{
if(s1[j]>s1[pos])
pos=j;
}
temp=s1[i1];
s1[i1]=s1[pos];
s1[pos]=temp;
}
for(i1 = 0; i1 < 7; i1++)
p[i1] = i1;
cout<<"\n Location Code\t\t crime_rate\t\t priority";
for(i1=0;i1<7;i1++)
{
cout<<"\n " << p[i1] << "\t\t\t    " << s1[i1] <<"\t\t\t    "<<i1+1;
}
takeInput();
cout<<"\nPath:\n";
mincost(0);
cout<<"\nMinimum Cost: "<< cost;
    return 0;
}

void takeInput()
{

int i,j;
cout<<"\n Enter the number of places to be patrolled: ";
cin>>n;
cout<<"\nEnter the Cost Matrix\n";
for(i=0;i < n;i++)
{
cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
for( j=0;j < n;j++)
cin>>ary[i][j];
completed[i]=0;
}
cout<<"\n\nThe cost list is:";
for( i=0;i < n;i++)
{
cout<<"\n";
for(j=0;j < n;j++)
cout<<"\t"<<ary[i][j];
}
}
void mincost(int city)
{
int ncity;
completed[city]=1;
cout<<city+1<<"--->";
ncity=least(city);
if(ncity==999)
{
ncity=0;
cout<<ncity+1;
cost+=ary[city][ncity];
return;
}
mincost(ncity);
}
int least(int c)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))

if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}
