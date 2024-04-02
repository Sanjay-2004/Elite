package day025;

// For X-Mas, santa claus is preparing an X-Mas Tree with set of Bulbs.
// The bulbs are of different voltages, and preparation of tree as follows:
// 	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
// 	  so on.
// 	- At level-0: There will be only one bulb as root bulb.,
// 	- From next level onwards, we can attach atmost two bulbs to left side,
// 	  and right side of every bulb in previous level.
// 	- The empty attachements in each level are indicated with null. 
// 	(for example: look in hint)

// You will be given the root of the X-Mas Tree,
// Your task is to findout the bulb with highest voltage in each level.

// Implement the class Solution:
// 1.public List<Integer> maxInEachRow(BinaryTreeNode root): returns the list of integers.

// Input Format:
// -------------
// A single line of space separated integers, voltages of the set of bulbs.

// Output Format:
// --------------
// Print the list of voltages.

// Sample Input-1:
// ---------------
// 2 4 3 6 4 -1 9

// Sample Output-1:
// ----------------
// [2, 4, 9]

// Sample Input-2:
// ---------------
// 3 4 7 7 3 8 4 

// Sample Output-2:
// ----------------
// [3, 4, 8]

//TreeNode Structure for Your Reference..
import java.util.*;

class Node {
    public int data;
    public Node left, right;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    public List<Integer> maxInEachRow(Node root) {
        // Implement Your Code here..
        // int h = findHeight(root);
        // int[] ans = new int[h];
        // System.out.println(h);
        // for(int i = 0;i<h;i++){
        // ans.add(0);
        // }
        List<Integer> ans = new ArrayList<>();
        findMax(root, ans, 1);
        // for(int i: ans){
        // res.add(i);
        // }
        return ans;
    }

    private int findHeight(Node root) {
        if (root == null)
            return 0;
        return 1 + Math.max(findHeight(root.left), findHeight(root.right));
    }

    private void findMax(Node root, List<Integer> ans, int level) {
        if (root == null)
            return;
        if (ans.size() >= level)
            ans.set(level - 1, Math.max(ans.get(level - 1), root.data));
        else
            ans.add(root.data);

        findMax(root.left, ans, level + 1);
        findMax(root.right, ans, level + 1);
    }
}
