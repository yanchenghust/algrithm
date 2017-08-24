/**
 * @author zybang
 * @time 2017/8/23 13:00
 * @desc take_coin.h
 * 有 n 个硬币排成一条线，每一枚硬币有不同的价值。
 * 两个参赛者轮流从任意一边取一枚硬币,直到没有硬币为止。
 * 计算拿到的硬币总价值，价值最高的获胜。
 * 请判定 第一个玩家 是输还是赢？
 * 给定数组 A = [3,2,2], 返回 true.
 * 给定数组 A = [1,2,4], 返回 true.
 * 给定数组 A = [1,20,4], 返回 false.
 *
 * m[i] i位置硬币面值
 * f(i,j)：i~j范围内先手能拿到的最大钱数
 * sum(i,j)：i~j范围内总钱数
 * f(i,j) = max{m[i]+sum(i+1,j)-f(i+1,j), m[j]+sum(i,j-1)-f(i,j-1)}
 * 此式不太好递推
 *
 * f(i,k)：i~i+k围内先手能拿到的最大钱数
 * sum(i,k)：i~i+k范围内总钱数
 * sum(i+1,k) = sum(i+1,k-1)+m[i+k+1]
 * f(i,k) = max{m[i]+sum(i+1,k-1)-f(i+1,k-1), m[i+k]+sum(i,k-1)-f(i,k-1)}
 * f(i,0) = m[i]
 **/

#ifndef C_TAKE_COIN_H
#define C_TAKE_COIN_H

#endif //C_TAKE_COIN_H

bool taskCoin1(int *m, int n){
    int dp[n][n];
    int sum[n][n];

    for(int k=0; k<n; k++){
        dp[k][0] = m[k];
        sum[k][0] = m[k];
    }
    for(int k=0; k<=n-1; k++){
        dp[n-1][k] = m[n-1];
        sum[n-1][k] = m[n-1];
    }
    int m1, m2;
    for(int i=n-1; i>=0; i--){
        for(int k=1; k<n && i+k<n; k++){
            if(i+1 >= n){
                m1 = m[i];
                m2 = m[i+k];
            }else{
                m1 = m[i] + sum[i+1][i+k] - dp[i+1][k-1];
                m2 = m[i+k] + sum[i][i+k-1] - dp[i][k-1];
            }
            dp[i][k] = m1 > m2? m1: m2;
        }
    }
}