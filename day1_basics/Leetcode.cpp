#include<iostream>
#include<string>

int main() {
	//一维数组的动态和
	int nums[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	const int length = sizeof(nums) / sizeof(nums[0]);
	int runningSum[length];
	runningSum[0] = nums[0];
	for (int i = 1; i < length; i++) {
		runningSum[i] = runningSum[i - 1] + nums[i];
	}
	for (int i = 0; i < length; i++) {
		
		std::cout << runningSum[i] << " ";
	}
	std::cout << std::endl;

	//反转字符串
	std::string str = "abcdefghigklmnopqrstuvwxyz";
	int Begin_Index = 0, End_Index = str.size() - 1;

	while (Begin_Index < End_Index) {
		char temp = str[Begin_Index];
		str[Begin_Index] = str[End_Index];
		str[End_Index] = temp;
		Begin_Index++, End_Index--;
	}
	std::cout << str << std::endl;
	std::cout << std::endl;
	return 0;
}
