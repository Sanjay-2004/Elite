// There are n cartons of binary string of lenght n, where carton[i] is '0' if the ith
// carton is empty and '1' if it contains one product.

// In one operation, you can move one product from a carton to an adjacent carton.
// cartoon i is adjacent to carton j if abs(i - j) == 1. Note that after doing so, there
// may be more than one product in some cartons.

// Return an array answer of size n, where answer[i] is the minimum number of operations
// needed to move all the products to the ith carton

// Each answer[i] is calculated considering the initial state of the cartons.

// Input Format
// ------------
// A string of zeroes and ones

// Output Format
// -------------
// An integer array which is minimum no of operations

// Sample Input-1:
// ===============
// 110

// Sample Output-1:
// ================
// 1 1 3

// Explanation:
// ============
// The answer for each cartoon is as follows:
// 1) First carton: you will have to move one product from the second carton to the first
// carton in one operation.
// 2) Second carton: you will have to move one product from the first carton to the second
// carton in one operation.
// 3) Third carton: you will have to move one product from the first carton to the third carton
// in two operations, and move one product from the second product to the third carton in
// one operation.

// Sample Input-2:
// ===============
// 001011

// Sample Output-2:
// ================
// 11 8 5 4 3 4

import java.util.*;

class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int sum = 0;
        int rc = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                rc++;
                sum += i;
            }
        }
        int lc = 0;
        if (s.charAt(0) == '1') {
            rc--;
            lc++;
        }
        System.out.print(sum + " ");
        for (int i = 1; i < n; i++) {
            sum -= rc;
            sum += lc;
            if (s.charAt(i) == '1') {
                lc++;
                rc--;
            }
            System.out.print(sum + " ");
        }
        sc.close();
    }
}
