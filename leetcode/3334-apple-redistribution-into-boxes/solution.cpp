class Solution {
public:
    void merge(vector<int>&arr , int left , int right , int mid){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> l1(n1),l2(n2);
        for(int i = 0 ; i< n1; i++){
            l1[i] = arr[left + i];
        }
        for(int i = 0 ; i<n2 ; i++){
            l2[i] = arr[mid + i +1];
        }
        int i = 0 , j = 0 , k = left;
        while(i < n1 && j < n2){
            if(l1[i]> l2[j]){
                arr[k++] = l1[i++];
            }
            else{
                arr[k++] = l2[j++];
            }
        }
        while(i<n1){
            arr[k++] = l1[i++];
        }
        while(j< n2){
            arr[k++] = l2[j++];
        }
    }
    void mergeSort(vector<int>&arr , int left , int right){
        if(left < right){
            int mid = left + (right-left) / 2;
            mergeSort(arr , left , mid);
            mergeSort(arr , mid+1 , right);
            merge(arr , left , right , mid);
        }
    }
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        mergeSort(capacity , 0 , capacity.size() - 1);
        int sum = 0;
        for(const auto q : apple){
            sum += q;
        }
        int count = 0;
        int i = 0;
        while(sum > 0){
            count++;
            sum -= capacity[i++];
        }
        return count;
    }
};
