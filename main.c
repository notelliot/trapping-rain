/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped
*/

#include <stdio.h>
#include <stdlib.h>

int get_biggest(int height[], int size){
    int biggest = height[0];
    for(int i = 1; i < size; i++){
	if(height[i] > biggest){
	    biggest = height[i];
	}
    }

    return biggest;
}

int water_level(int height[], int size){
    int tallest = 0;
    int water = 0;
    int biggest = get_biggest(height, size);

    for(int i = 0; i < size - 1; i++){
	if(height[i] > tallest && height[i] != biggest){
	    tallest = height[i];
	}
	else if(height[i] < biggest){
	    water += tallest - height[i];
	}
    }

    return water;
}

int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(height)/sizeof(height[0]);
    
    printf("%d", water_level(height, size));

    return 0;
}
