#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        return search_help(nums,left,right,target);
    }
    int search_help(vector<int>& nums,int left,int right,int target){
        int mid = left + (right - left) >> 1;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target){
            return search_help(nums,mid+1,right,target);
        } else {
            return search_help(nums,left,mid-1,target);
        }
    }
};

int main()
{

}