/**
 * @author zybang 
 * @time 2017/8/16 9:48
 * @desc lcs.h 最长公共子序列
 * 例如：
 * char str1[]="123456789";
 * char str2[]="173450689";
 * int len = lcs(str1, str2);
 * printf("len: %d", len);
 **/
#include <string.h>

#ifndef C_LCS_H
#define C_LCS_H

#endif //C_LCS_H

int lcs(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1][len2] = {{0}};
    dp[0][0] = str1[0]==str2[0]? 1: 0;
    for(int i=1; i<len2; i++){
        dp[0][i] = dp[0][i-1] || (str1[0]==str2[i]);
    }
    for(int i=1; i<len1; i++){
        dp[i][0] = dp[i-1][0] || (str1[i]==str2[0]);
    }
    for(int i=1; i<len1; i++){
        for(int j=1; j<len2; j++){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = dp[i-1][j]>dp[i][j-1]? dp[i-1][j]: dp[i][j-1];
            }
        }
    }
    return dp[len1-1][len2-1];
}
