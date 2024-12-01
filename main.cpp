#include<iostream>
#include<vector>
using namespace std;

vector<int> operator+(vector<int>& v1,vector<int>& v2){
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
}


vector<int> quick_sort(vector<int> nums) {
    if (nums.size() <= 1) {
        return nums;
    }
    vector<int> left;
    vector<int> right;
    int pivot = nums[0];
    
    
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < pivot) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
    }
    
    //vector<int> sorted_left = quick_sort(left);
    //vector<int> sorted_right = quick_sort(right);
    //sorted_left.push_back(pivot);  // 将 pivot 放入合适位置
    //sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());  // 将右边的结果添加到末尾
    left = quick_sort(left);
    right=quick_sort(right);
    left.push_back(pivot);
    left+right;
    return left;
}


int main(){
    vector<int> test ={7,4,2,8,10,200};
    vector<int> res = quick_sort(test);
    for(int val:res){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}