#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_map>
using namespace std;
typedef pair<int, vector<int>> PIV;
typedef pair<string, double> PSD;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double>hash{ {"",0} };
        for (int i = 0; i < equations.size(); i++) {
            if (hash[equations[i][0]] == 0 && hash[equations[i][1]] == 0) {
                hash[equations[i][1]] = 1;
                hash[equations[i][0]] = hash[equations[i][1]] * values[i];
            }
            else if (hash[equations[i][0]]) {
                hash[equations[i][1]] = hash[equations[i][0]] / values[i];
            }
            else if (hash[equations[i][1]]) {
                hash[equations[i][0]]= hash[equations[i][1]] * values[i];
            }
        }
        vector<double > res;
        for (int i = 0; i < queries.size(); i++) {
            if (hash[queries[i][0]] == 0 && hash[queries[i][1]] == 0) {
                res.push_back(queries[i][0] == queries[i][1] ? 1 : -1);
            }
            else if (hash[queries[i][0]] == 0 || hash[queries[i][1]] == 0) {
                res.push_back(-1);
            }
            else {
                res.push_back(hash[queries[i][0]] / hash[queries[i][1]]);
            }
        }
        return res;
    }
};
class Solution {
public:
    unordered_map<int ,vector<int>>hash;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }
        srand((unsigned)time(NULL));
    }
    int pick(int target) {
        return hash[target][rand() % hash[target].size()];
    }
};
class Solution {
public:
    int res = 0;
    void minTime(long n) {
        if (n == 1)return;
        else if (n == 3) {
            res += 2;
            return;
        }
        if (n % 2) {
            res++;
            (n + 1) % 4 == 0 ? minTime(n + 1) : minTime(n - 1);
        }
        else {
            res++;
            minTime(n / 2);
        }
    }
    int integerReplacement(int n) {
        if (n == 1) return 0;
        minTime(n);
        return res;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int res = 0;
        int num = 0;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            num += i * nums[i];
        }
        res = num;
        for (int i = 0; i < nums.size(); i++) {
            num = num + sum - n * nums[n - i - 1];
            res = max(res, num);
        }
        return res;
    }
};
//class Solution {
//public:
//    int res = 0;
//    void maxLength(string s, int a, int b, int k) {
//        vector<int>vec(26, 0);
//        for (int i = a; i < b; i++) {
//            vec[s[i] - 'a']++;
//        }
//        int idx = a;
//        int flag = 1;
//        for (int i = a; i < b; i++) {
//            if (vec[s[i]-'a'] > 0 && vec[s[i]-'a'] < k) {
//                maxLength(s, idx, i, k);
//                idx = i+1;
//                flag = 0;
//            }
//        }
//        if (flag)
//        {
//            res = max(res, b - a);
//            return;
//        }
//        maxLength(s, idx, b, k);
//    }
//    int longestSubstring(string s, int k) {
//        maxLength(s, 0, s.length(), k);
//        return res;
//    }
//};