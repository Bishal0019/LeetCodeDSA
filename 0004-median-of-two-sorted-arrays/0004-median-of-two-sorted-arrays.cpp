class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0; 
        int j=0;
        vector<int> sorted;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                sorted.push_back(nums1[i]);
                i++;
            } else {
                sorted.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size()){
            sorted.push_back(nums1[i++]);
        }
        while(j<nums2.size()){
            sorted.push_back(nums2[j++]);
        }

        int mid = sorted.size() / 2;
        if(sorted.size() == 0) return 0;
        else if(sorted.size() == 1) return (double)sorted[0];
        else if(sorted.size() % 2 == 0){
            return (double)(sorted[mid] + sorted[mid-1])/2;
        }
        else return (double)sorted[mid];
    }
};