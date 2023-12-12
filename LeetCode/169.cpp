#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {

        int count=0;
        int maj; 
        for (int i=0;i<nums.size();i++){
            if(count==0){
                count++;
                maj=nums[i];
            }
            else if (maj==nums[i])
                count++;
            else
                count--;
        //Majority element will always stick out even after traversing through all elements

        }
        return maj;

    }

int main(){
    vector <int> v={7,2,7,2,7,3,6,7,7};
    cout<<majorityElement(v);

    return 0;
}