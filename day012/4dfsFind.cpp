// Given a matrix of 0's and 1's of dimension rows X cols.

// We could traverse from one element(row, col) to any other element(row + 1, col) or (row, col + 1).

// Print 'true' if there is any path from first element(0,0) of the matrix to the last element(rows - 1, cols - 1)
// of the matrix that visits the same number of 1's and 0's.
// Print 'false' otherwise.

// Input Format
// -------------
// Line-1: Read two integers rows and cols(space separated).
// Line-2: Read the matrix of dimension rows X cols.

// Output Format
// --------------
// If the required path exist print 'true' otherwise 'false'.

// Sample input-1:
// ---------------
// 3 4
// 0 1 1 0
// 0 0 0 0
// 0 0 1 0

// Sample output-1:
// ----------------
// true

// Explanation: In the given matrix there is a path that is having three 0's and three 1's.

// Sample input-2:
// ---------------
// 4 3
// 0 0 1
// 1 0 0
// 0 0 0
// 0 0 1

// Sample output-2:
// ----------------
// false

// Explanation: There is NO path that is having same number of 0's and 1's.
