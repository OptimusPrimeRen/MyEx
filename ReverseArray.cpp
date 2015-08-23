#include <iostream>

using namespace std;

void reverseArray(char array[],int length){
    if(length>1){
        int left = 0;
        int right = length - 1;
        while(left<right){
            char temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}

int main()
{
    char name[] = {'1','2','3'};
    int length = 3;
    reverseArray(name,length);

    for(int i=0;i<=length-1;i++){
        cout<<name[i]<<endl;
    }
    return 0;
}
