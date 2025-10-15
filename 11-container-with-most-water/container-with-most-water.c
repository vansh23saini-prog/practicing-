int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int max_water = 0;

    while (left < right) {
        int width = right - left;
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = width * h;
        if (area > max_water)
            max_water = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_water;
}
