Contest Answers:

1. 
int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int ans = 1e9;

    for (int i = 0; i < landStartTime.size(); i++) {
        for (int j = 0; j < waterStartTime.size(); j++) {
            int landEnd = landStartTime[i] + landDuration[i];
            int waterStart = max(landEnd, waterStartTime[j]);
            int finishTime1 = waterStart + waterDuration[j];
            ans = min(ans, finishTime1);
    
            int waterEnd = waterStartTime[j] + waterDuration[j];
            int landStart = max(waterEnd, landStartTime[i]);
            int finishTime2 = landStart + landDuration[i];
            ans = min(ans, finishTime2);
        }
    }
    
    return ans;    
}

2. 
int minRemovals(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, validIdx = i;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= k * nums[i]) {
                validIdx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        maxLen = max(maxLen, validIdx - i + 1);
    }

    return n - maxLen;
}

3.
int ans = 1e9;

// First we calc for land
int minEnd = 1e9;
for (int i = 0; i < landStartTime.size(); i++) {
    minEnd = min(minEnd, landStartTime[i] + landDuration[i]);
}
// Ans = min of land + water
for (int i = 0; i < waterStartTime.size(); i++) {
    int x = waterDuration[i] + max(minEnd, waterStartTime[i]);
    ans = min(ans, x);
}

// Now we calc for water
minEnd = 1e9;
for (int i = 0; i < waterStartTime.size(); i++) {
    minEnd = min(minEnd, waterStartTime[i] + waterDuration[i]);
}
// Ans = min of water + land
for (int i = 0; i < landStartTime.size(); i++) {
    int x = landDuration[i] + max(minEnd, landStartTime[i]);
    ans = min(ans, x);
}

return ans;

4.
NOT SOLVED