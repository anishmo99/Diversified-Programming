class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size(); 
        int XOR = nums[0];
        
        for(int i = 1; i < n; i++){
            XOR = XOR^nums[i];
        }
        
        int set_bit_no = XOR & ~(XOR - 1);
        
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] & set_bit_no)
                a = a^nums[i];
            else
                b = b^nums[i];
        }
        
        if(a < b)
            return {a, b};
        else
            return {b, a};
    }
};