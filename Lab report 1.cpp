#include<iostream>
using namespace std;
int LinearSearch(char arr[],int n,int kee)
{
for(int i=0;i<n;i++)
{
if(arr[i]==kee)
{
return i;
}
}
return -1;
}
int main()
{
int n;
cout<<"Enter range : ";
cin>>n;
char arr[n+1];
cin>>arr;
char kee;
cout<<"Find character : ";
cin>>kee;
cout<<LinearSearch(arr,n,kee);
}
\\



#include<iostream>
using namespace std;
int BinarySearch(char arr[],int n,int value)
{
int start=0;
int last=n-1;
while(start<=last)
{
int mid=(start+last)/2;

if(arr[mid]==value)
return mid;
else if(arr[mid]>value)
last=mid-1;
else if(arr[mid]<value)
start=mid+1;
}
  return -1;
}

int main()
{
int n;
cout<<"Enter range : ";
cin>>n;
char arr[n+1];
cout<<"Enter character : ";
cin>>arr;
cout<<"Find character :";
char kee;
cin>>kee;
cout<<BinarySearch(arr,n,kee);
}
 \\
   
   
 
  
 #include<iostream>
using namespace std;
int LinearSearch(char arr[],int n,int kee)
{
if(n<0)
return -1;
else if(arr[n]==kee)
return n;
return LinearSearch( arr,n-1, kee);
}
int main()
{
int n;
cout<<"Enter range : ";
cin>>n;
char arr[n+1];
cin>>arr;
char kee;
cout<<"Find character : ";
cin>>kee;
cout<<LinearSearch(arr,n,kee);
}
\\


#include<iostream>
using namespace std;
int BinaryRecursion(char arr[],int kee ,int low,int high)
{
int mid = (low+high)/2;
if(low<=high){
if(arr[mid]==kee){
return mid;
}
else if(arr[mid] < kee){
low = mid + 1;
}
else if(arr[mid] > kee){
high = mid - 1;
}
return BinaryRecursion(arr, kee, low, high);
}else{
return -1;
}
}
int main()
{
int low = 0,high = 5;
cout<<"Enter character : ";
char arr[6];
cin>>arr;
cout<<"Find character : ";
char kee;
cin>>kee;
cout<<BinaryRecursion(arr,kee,low,high);
}
\\



  
