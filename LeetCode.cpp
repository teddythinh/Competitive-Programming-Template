#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

bool checkPalindrome(int s) {
    string str = to_string(s);
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    if (len == 0) {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < len; i++) {
        int j = 0;
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    ListNode* head = nullptr;
    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }
    ListNode* cur = head;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (list1 != nullptr) {
        cur->next = list1;
    }
    if (list2 != nullptr) {
        cur->next = list2;
    }
    return head;        
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> temp;
    if(root == NULL) {
        return temp;
    }
    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);
    temp.insert(temp.end(), left.begin(), left.end());
    temp.push_back(root->val);
    temp.insert(temp.end(), right.begin(), right.end());
    return temp;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> temp;
    if(root == NULL) {
        return temp;
    }
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    temp.push_back(root->val);
    temp.insert(temp.end(), left.begin(), left.end());
    temp.insert(temp.end(), right.begin(), right.end());
    return temp;
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) {
        return true;
    }
    int left = 0;
    int right = 0;
    if(root->left != NULL) {
        left = 1 + isBalanced(root->left);
    }
    if(root->right != NULL) {
        right = 1 + isBalanced(root->right);
    }
    if(abs(left - right) > 1) {
        return false;
    }
    return true;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> temp;
    if(root == NULL) {
        return temp;
    }
    vector<TreeNode*> cur;
    cur.push_back(root);
    while(cur.size() != 0) {
        vector<int> level;
        vector<TreeNode*> next;
        for(int i = 0; i < cur.size(); i++) {
            level.push_back(cur[i]->val);
            if(cur[i]->left != NULL) {
                next.push_back(cur[i]->left);
            }
            if(cur[i]->right != NULL) {
                next.push_back(cur[i]->right);
            }
        }
        temp.push_back(level);
        cur = next;
    }
    return temp;
}

bool isCousins(TreeNode* root, int x, int y) {
    if(root == NULL) {
        return false;
    }
    if(root->val == x || root->val == y) {
        return false;
    }
    int left = 0;
    int right = 0;
    if(root->left != NULL) {
        left = isCousins(root->left, x, y);
    }
    if(root->right != NULL) {
        right = isCousins(root->right, x, y);
    }
    if(left == 1 && right == 1) {
        return true;
    }
    if(left == 1 && root->right != NULL && root->right->val == x) {
        return true;
    }
    if(right == 1 && root->left != NULL && root->left->val == x) {
        return true;
    }
    return false;
}

int largestPerimeter(vector<int>& nums) {
    // the perimeter of a triangle 
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if(nums[0] + nums[1] <= nums[2]) {
        return 0;
    }
    if(nums[1] + nums[2] <= nums[0]) {
        return 0;
    }
    if(nums[2] + nums[0] <= nums[1]) {
        return 0;
    }
    for (int i = len - 1; i >= 2; i--) {
        if (nums[i] + nums[i - 1] > nums[i - 2]) {
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> temp;
    for(int i = 0; i < nums.size(); i++) {
        temp.push_back(nums[i] * nums[i]);
    }
    sort(temp.begin(), temp.end());
    return temp;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    return p->left == q->left && p->right == q->right && p->val == q->val;
}

int lengthOfLastWord(string s) {
    int len = 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    return len;
}

vector<int> plusOne(vector<int>& digits) {
    vector<int> temp;
    int carry = 1;
    for(int i = digits.size() - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        if(sum >= 10) {
            carry = 1;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        temp.push_back(sum);
    }
    if(carry == 1) {
        temp.push_back(1);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

string addBinary(string a, string b) {
    string temp;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    for(; i >= 0 && j >= 0; i--, j--) {
        int sum = a[i] - '0' + b[j] - '0' + carry;
        if(sum >= 2) {
            carry = 1;
            sum = sum % 2;
        } else {
            carry = 0;
        }
        temp.push_back(sum + '0');
    }
    if(i >= 0) {
        for(; i >= 0; i--) {
            int sum = a[i] - '0' + carry;
            if(sum >= 2) {
                carry = 1;
                sum = sum % 2;
            } else {
                carry = 0;
            }
            temp.push_back(sum + '0');
        }
    } else if(j >= 0) {
        for(; j >= 0; j--) {
            int sum = b[j] - '0' + carry;
            if(sum >= 2) {
                carry = 1;
                sum = sum % 2;
            } else {
                carry = 0;
            }
            temp.push_back(sum + '0');
        }
    }
    if(carry == 1) {
        temp.push_back('1');
    }
    reverse(temp.begin(), temp.end());
    return temp;
}


bool isSquare(int num) {
    int i = 1;
    while(i * i <= num) {
        if(i * i == num) {
            return true;
        }
        i++;
    }
    return false;
}

int mySqrt(int x) {
    if(x == 0) {
        return 0;
    }   
    int left = 1;
    int right = x;

}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> temp;
    if(root == NULL) {
        return temp;
    }
    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);
    temp.insert(temp.end(), left.begin(), left.end());
    temp.insert(temp.end(), right.begin(), right.end());
    temp.push_back(root->val);
    return temp;
}

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> temp;
    if(numRows == 0) {
        return temp;
    }
    vector<int> row;
    row.push_back(1);
    temp.push_back(row);
    for(int i = 1; i < numRows; i++) {
        row.clear();
        row.push_back(1);
        for(int j = 1; j < i; j++) {
            row.push_back(temp[i - 1][j - 1] + temp[i - 1][j]);
        }
        row.push_back(1);
        temp.push_back(row);
    }
    return temp;
}

vector<int> getRowInPascalTriangle(int rowIndex) {
    vector<int> temp;
    if(rowIndex == 0) {
        temp.push_back(1);
        return temp;
    }
    temp.push_back(1);
    for(int i = 1; i < rowIndex; i++) {
        temp.push_back(1);
        for(int j = i - 1; j > 0; j--) {
            temp[j] = temp[j] + temp[j - 1];
        }
    }
    temp.push_back(1);
    return temp;
}

int maxProfit(vector<int>& prices) {
    int buy = INT_MIN;
    int sell = 0;
    int profit = 0;
    for(int i = 0; i < prices.size(); i++) {
        buy = max(buy, -prices[i]);
        sell = max(sell, prices[i] + buy);
        profit = max(profit, sell);
    }
    return profit;
}

bool checkPerfectNumber(int num) {
    int sum = 1;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i;
            sum += num / i;
        }
    }
    return sum == num;
}

vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0 && i % 5 == 0) { ans.push_back("FizzBuzz"); }
        else if (i % 3 == 0) { ans.push_back("Fizz"); }
        else if (i % 5 == 0) { ans.push_back("Buzz"); }
        else { ans.push_back(to_string(i)); }
    }
    return ans;
}

string convertToBase7(int num) {
    string temp;
    if(num == 0) {
        return "0";
    }
    int flag = 1;
    if(num < 0) {
        flag = -1;
        num = -num;
    }
    while(num > 0) {
        temp.push_back(num % 7 + '0');
        num /= 7;
    }
    if(flag == -1) {
        temp.push_back('-');
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

bool isHappyNumber(int n) {
    // if n is 1, return true
    // if n is not 1, return false
    int sum = 0;
    int temp = n;
    while(temp != 1) {
        sum = 0;
        while(temp > 0) {
            sum += (temp % 10) * (temp % 10);
            temp /= 10;
        }
        temp = sum;
    }
    return sum == 1;
}

ListNode* remove(ListNode* head, int val) {
    if(head == NULL) {
        return NULL;
    }
    if(head->val == val) {
        return remove(head->next, val);
    }
    head->next = remove(head->next, val);
    return head;
}


ListNode* reverseList(ListNode* head) {
    if(head == NULL) {
        return NULL;
    }
    ListNode* temp = head;
    ListNode* pre = NULL;
    while(temp != NULL) {
        ListNode* next = temp->next;
        temp->next = pre;
        pre = temp;
        temp = next;
    }
    return pre;
}

bool containDuplicate(vector<int>& nums) {
    vector<int> temp;
    for(int i = 0; i < nums.size(); i++) {
        if(find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
            temp.push_back(nums[i]);
        } else {
            return true;
        }
    }
    return false;
}

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void moveZeroes(vector<int>& nums) {
    // move all the non-zero elements to the front
    // move all the zero elements to the end
    int i = 0;
    int j = 0;
    while(j < nums.size()) {
        if(nums[j] != 0) {
            nums[i++] = nums[j];
        }
        j++;
    }

}

bool isPowerOfThree(int n) {
    if(n == 0) {
        return false;
    }
    while(n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

void reverseString(vector<char>& s) {
    vector<char> temp;
    for(int i = s.size() - 1; i >= 0; i--) {
        temp.push_back(s[i]);
    }
    s = temp;
}

int majorityElement(vector<int>& nums) {
    int count = 0;
    int temp = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(count == 0) {
            temp = nums[i];
        }
        if(nums[i] == temp) {
            count++;
        } else {
            count--;
        }
    }
    return temp;
}

int hammingDistance(int x, int y) {
    int temp = x ^ y;
    int count = 0;
    while(temp > 0) {
        if(temp % 2 == 1) {
            count++;
        }
        temp /= 2;
    }
    return count;
}

int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

string toLowerCase(string s) {
    string temp;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            temp.push_back(s[i] + 32);
        } else {
            temp.push_back(s[i]);
        }
    }
    return temp;
}

bool isSameAfterReversals(int num) {
    int temp = num;
    int reverse = 0;
    while(temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return num == reverse;
}

int main() {
    
}
