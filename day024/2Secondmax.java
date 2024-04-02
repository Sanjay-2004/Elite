package day024;

// In a Marketing Agency, each agent will mentor either two sub-agents,
// or zero agents. Now, based on ranks given to sub-agents, the mentor agent 
// will be ranked with the top rank among two sub-agents. 

// The ranks are in the range [1,20], More than one agent can have same rank.

// At the end, all mentor agents and sub agents, will be treated as agents only.

// You are given the entire ranking picture as a tree.
// Your task is to find out second top agent in the Marketing agency and 
// print the agent's rank, If no such agent exist, print -2.

// Implement the class Solution:
//    1. public int findSecondTopAgent(BinaryTreeNode root): returns an integer.

// NOTE:
// 	- In the input '-1', indicates empty(null).

// Input Format:
// -------------
// A single line of space separated integers, ranks of each individual.

// Output Format:
// --------------
// Print an integer, second top agent based on rank.

// Sample Input-1:
// ---------------
// 2 5 2 -1 -1 2 4

// Sample Output-1:
// ----------------
// 4

// Sample Input-2:
// ---------------
// 3 3 3 3 3

// Sample Output-2:
// ----------------
// -2

// ::For Tree structure refer to Hint::

import java.util.*;

class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

class Solution {
    int m1 = Integer.MAX_VALUE;
    int m2 = Integer.MAX_VALUE;

    private void findSecond(Node root) {
        if (root == null || root.data == -1)
            return;
        if (root.data < m1) {
            m2 = m1;
            m1 = root.data;
        } else if (root.data > m1 && root.data < m2) {
            m2 = root.data;
        }
        findSecond(root.left);
        findSecond(root.right);
    }

    public int findSecondTopAgent(Node root) {
        // implement your code here.
        findSecond(root);
        return m2 != Integer.MAX_VALUE ? m2 : -2;
    }
}
