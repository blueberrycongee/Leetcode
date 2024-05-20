class Solution {
public://思路:从下往上，反推路径，返回从最底层到最上层最小的路径和,将dp数组初始化为最底层元素,然后上一层对应的值为两个条可到达的路中路径和较小的值
        //同时，自下而上还不需要考虑边界问题
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>dp(triangle.back());
        for(int i = m-2;i>=0;i--)  //从下往上分层遍历,最后一层的路径和已经初始化好了，从倒数第二层开始计算即可
        {
            for(int j = 0;j<=i;j++) 
            {
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];//这层的第j个元素，可以从下一层的第i或者i+1的元素那里转移过来，取较小值。
            }
        }
        return dp[0];   //返回到达最上层元素的值就是最小路径和
    }
};
