class Solution
{
public:
    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        while (high >= low)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (target > nums[mid])
            {
                low = mid + 1;
                continue;
            }

            high = mid - 1;
        }

        return -1;
    }

    int findPivot(vector<int> &nums, int low, int high)
    {
        while (high > low)
        {
            int mid = low + (high - low) / 2;

            if (mid < high and nums[mid] > nums[mid + 1])
                return mid;

            if (mid > low and nums[mid] < nums[mid - 1])
                return mid - 1;

            if (nums[low] < nums[mid])
            {
                low = mid + 1;
                continue;
            }
            high = mid - 1;
        }

        return -1;
    }

    int pivotBS(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums, 0, nums.size() - 1);

        if (pivot == -1)
            return binarySearch(nums, 0, nums.size() - 1, target);

        if (nums[pivot] == target)
            return pivot;

        if (nums[0] > target)
            return binarySearch(nums, pivot + 1, nums.size() - 1, target);
        return binarySearch(nums, 0, pivot - 1, target);
    }

    int search(vector<int> &nums, int target)
    {
        return pivotBS(nums, target);
    }
};