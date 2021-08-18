#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isBadVersion(int x);
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid) == true){
                if( (mid-1 == 0) || isBadVersion(mid-1) == false)
                    return mid;
                if(isBadVersion(mid-1) == true)
                    right = mid - 1;
            } 
            if(isBadVersion(mid) == false){
                //还可加一个判断，就是没有出错的版本
                if(isBadVersion(mid+1) == true)
                    return mid+1;
                if(isBadVersion(mid+1) == false)
                    left = mid + 1;
            }
        }
    }
};