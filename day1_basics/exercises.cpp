#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
void function1() {
	int num1 = 2, num2 = 4;
	std::cout << "交换前：" << num1 << ", " << num2 << std::endl;
	int temp = num1;
	num1 = num2;
	num2 = temp;
	std::cout << "交换后：" << num1 << ", " << num2 << std::endl;
}
void function2() {
	int num1 = 5, num2 = 3, num3 = 8;
	if (num1 >= num2 && num1 >= num3) {
		std::cout << "最大值为" << num1 << std::endl;
	}
	else if (num2 >= num1 && num2 >= num3) {
		std::cout << "最大值为" << num2 << std::endl;
	}
	else {
		std::cout << "最大值为" << num3 << std::endl;
	}
}
void function3() {
	int count = 20;
	int sum = 0;
	for (int i = 1; i < count + 1; i++) {
		sum += i;
	}
	std::cout << "1-" << count << "求和为：" << sum << std::endl;
}
void function4() {
	int num;
	std::cout << "请输入num值：";
	std::cin >> num;
	if (num == 0) {
		std::cout << num << "为0" << std::endl;
	}
	else if (num % 2 != 0) {
		std::cout << num << "为奇数" << std::endl;
	}
	else {
		std::cout << num << "为偶数" << std::endl;
	}
}
void function5() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << j << " * " << i << " = " << j * i << "\t";
		}
		std::cout << std::endl;
	}
}

void function6() {
	int arr[] = { 1,5,8,6,48,3,5,4,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int MAXIndex = 0, MINIndex = 0;
	for (int i = 1; i < len; i++) {
		if (arr[i] > arr[MAXIndex]) {
			MAXIndex = i;
		}
		if (arr[i] < arr[MINIndex]) {
			MINIndex = i;
		}
	}
	std::cout << "数组最大值为：" << arr[MAXIndex] << "，数组最小值为：" << arr[MINIndex] << std::endl;
}
void function7() {
	std::string str1 = "sfafgatgwtawf";
	std::cout << "字符串长度为：" << str1.size() << std::endl;
}
int main() {
	function1();
	function2();
	function3();
	function4();
	function5();
	function6();
	function7();
	return 0;
}
