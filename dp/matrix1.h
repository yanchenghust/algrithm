/**
 * @author zybang 
 * @time 2017/8/15 15:03
 * @desc 给定一个矩阵M，左上角为入口，右下角为出口，每次只能向右或向下移动。路径上所有数字加起来为路径和Sum。求从入口到出口Sum的最大值。
 * 如矩阵：
 * 1    3	4
 * 2	6	3
 * 3	2	5
 * 则Sum的最大值为18（路径为1 3 6 3 5）
 **/

#ifndef C_MATRIX1_H
#define C_MATRIX1_H

#endif //C_MATRIX1_H


/**
 *
 * @param m 矩阵
 * @param cols 列数
 * @param rows 行数
 * @return
 */
int maxSum(int **m, int cols, int rows){
    int dp[rows][cols] = {{0}};
    int tmp;
    dp[0][0] = m[0][0];
    for(int i=1; i<rows; i++) {
        dp[i][0] = dp[i-1][0] + m[i][0];
    }
    for(int j=1; j<cols; j++) {
        dp[0][j] = dp[0][j-1] + m[0][j];
    }
    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){
            tmp = dp[i-1][j] > dp[i][j-1]? dp[i-1][j]: dp[i][j-1];
            dp[i][j] = tmp + m[i][j];
        }
    }
    int sum = dp[rows-1][cols-1];
    return sum;
}
