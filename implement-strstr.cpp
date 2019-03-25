//
// Created by fyyc on 19-3-25.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        string::size_type idx = haystack.find(needle);
        return (idx == string::npos ? -1 : int(idx));
    }
};

int main(){
    Solution solution;
    cout<<solution.strStr( "hello", "ll")<<endl;
}