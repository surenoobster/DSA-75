
class Solution {
public:
    // Method to check if Koko can eat all bananas at speed `k` within `h` hours
    bool canEatAllBananas(const vector<int>& piles, int speed, int h) {
        int totalHours = 0;
        for (int pile : piles) {
            // Calculate the number of hours needed to finish each pile at the current speed
            totalHours += ceil((double)pile / speed);
            if (totalHours > h) {
                return false; // If the total hours exceed h, we can't eat all in time
            }
        }
        return totalHours <= h;
    }

    // Main method to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // Minimum speed is 1 banana/hour
        int right = *max_element(piles.begin(), piles.end()); // Maximum speed is the largest pile

        // Perform binary search to find the minimum speed
        while (left < right) {
            int mid = left + (right - left) / 2; // Find the middle speed
            if (canEatAllBananas(piles, mid, h)) {
                right = mid; // Try for a lower speed
            } else {
                left = mid + 1; // Increase the speed
            }
        }

        return left; // The minimum speed that allows Koko to eat all bananas within `h` hours
    }
};
