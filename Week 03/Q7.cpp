/*Date: 17/2/25
Prog: Insertion Sort*/

#include <iostream>
using namespace std;

void insertion(int arr[],int n)
{
    int c=0,shift=0;
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            c++;
            arr[j+1]=arr[j];
            shift++;
            j=j-1;
            
        }
        arr[j+1]=key;
    }
    cout<<"Comparsion"<<c<<endl;
    cout<<"Shift"<<shift<<endl;
    cout<<"Array";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int n;
    cout <<"Enter the size:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    insertion(arr,n);
    
}
