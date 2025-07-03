class Solution {
public:
    double findMedian(int n , int m , vector<int> nums1 , vector<int> nums2){
        int start = 0;
        int end = n;
        while(true){
            int mid = (start+end)/2;
            int position = (n+m)/2 - mid;
            int midNum , positionNum , midNum1 , positionNum1;
            if(mid == 0){
                midNum = INT_MIN;
                midNum1 = nums1[mid];
            }
            else if(mid >= n){
                midNum1 = INT_MAX;
                midNum = nums1[mid - 1];
            }
            else{
                midNum = nums1[mid - 1];
                midNum1 = nums1[mid];
            }
            if(position == 0){
                positionNum = INT_MIN;
                positionNum1 = nums2[position];
            }
            else if(position >= m){
                positionNum1 = INT_MAX;
                positionNum = nums2[position -1] ;
            }
            else{
                positionNum = nums2[position -1] ;
                positionNum1 = nums2[position];
            }
            if(positionNum1 >= midNum && positionNum <= midNum1){
                if((n+m) % 2 != 0){
                    return min(positionNum1 , midNum1);
                }
                else{
                    double answer = (max(midNum , positionNum) + min(midNum1 , positionNum1)) / 2.0;
                    return answer;
                }
            }
            else if(positionNum1 <= midNum && positionNum <= midNum1){
                end = mid - 1;
            }
            else if(positionNum1 >= midNum && positionNum >= midNum1){
                start = mid + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0){
            if((m)%2 != 0){
                return nums2[m/2];
            }
            else{
                return (nums2[m/2] + nums2[(m/2) -1])/2.0;
            }
        }
        if(m == 0){
            if((n)%2 != 0){
                return nums1[n/2];
            }
            else{
                return (nums1[n/2] + nums1[(n/2) - 1])/2.0;
            }
        }
        if(n <= m){
            return findMedian(n,m,nums1 , nums2);
        }
        else{
            return findMedian(m , n , nums2 , nums1);
        }
    }
};
