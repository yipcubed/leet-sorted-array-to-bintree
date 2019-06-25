#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // print it by level
ostream& operator<<(ostream& os, TreeNode* tr) {
  queue<TreeNode*> q;
  bool first = true;
  int level = 1;
  os << "[";
  if (tr) q.push(tr);
  while (!q.empty()) {
    int nodeCount = q.size();
    while (nodeCount > 0) {
      cout << "level:(" << level++ << ") ";
      TreeNode* tp = q.front();
      q.pop();
      if (first) {
        os << tp->val;
        first = false;
      } else {
        os << "," << tp->val;
      }
      if (tp->left) q.push(tp->left);
      if (tp->right) q.push(tp->right);
      --nodeCount;
    }
  }
  os << "]";
  return os;
}

ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[";
  for (int i : v) {
    os << i << " ";
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int finish) {
        if (start > finish)
          return nullptr;
        int middle = start + (finish - start + 1) / 2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = sortedArrayToBST(nums, start, middle - 1);
        root->right = sortedArrayToBST(nums, middle + 1, finish);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};

void test1() {
  Solution S;
  vector<int> v1{-10,-3,0,5,9};
  cout << v1 << endl;
  cout << "[0,-3,9,-10,null,5]? " << S.sortedArrayToBST(v1) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}
