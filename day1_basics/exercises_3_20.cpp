#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

template<typename T>
void function1(T* m_num1, T* m_num2) {
	T temp = *m_num1;
	*m_num1 = *m_num2;
	*m_num2 = temp;
}

double Average(int* arr, int len) {
	if (len == 0) return 0;
	int sum = 0;
	for(int i = 0;i<len;i++){
		sum += arr[i];
	}
	return 1.0 * sum / len;
}
void Reverse(int* arr, int len) {
	int beginIndex = 0, endIndex = len - 1;
	while (beginIndex < endIndex) {
		int temp = arr[beginIndex];
		arr[beginIndex] = arr[endIndex];
		arr[endIndex] = temp;
		beginIndex++, endIndex--;
	}
}
int Count(const std::string& str, char x) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == x) {
			count++;
		}
	}
	return count;
}
bool Palindrome(const std::string& str) {
	 if(str.empty()) return true;
	 int beginIndex = 0, endIndex = str.size() - 1;
	 while (beginIndex < endIndex) {
		 if (str[beginIndex] != str[endIndex]) {
			 return false;
		 }
		 beginIndex++, endIndex--;
	 }
	 return true;
}

int MyStrlen(const char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
void MyStrcpy(char* dest, const char* src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int main() {
	//交换两个变量（指针版）
	int a = 2, b = 4;
	std::cout << "交换前：" << a << "," << b << std::endl;
	function1(&a, &b);
	std::cout <<"交换后：" << a << "," << b << std::endl;
	std::string str1 = "arfa", str2 = "egewg";
	std::cout << "交换前：" << str1 << "," << str2 << std::endl;
	function1(&str1, &str2);
	std::cout << "交换后：" << str1 << "," << str2 << std::endl;
	//求数组平均值
	int str[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(str) / sizeof(str[0]);
	double average = Average(str, len);
	std::cout << "平均数为：" << average << std::endl;
	//反转数组
	std::cout << "反转前：";
	for (int i = 0; i < len; i++) {
		std::cout << str[i] << ",";
	}
	std::cout << std::endl;
	Reverse(str, len);
	std::cout << "反转后：";
	for (int i = 0; i < len; i++) {
		std::cout << str[i] << ",";
	}
	std::cout << std::endl;
	//统计字符串中某字符出现次数
	std::string str3 = "asfagegagafs";
	char x = 'a';
	int count = Count(str3, x);
	std::cout << x << "在字符串" << str3 << "中出现了" << count << "次" << std::endl;
	//判断回文字符串
	std::string str4 = "abcba";
	if (Palindrome(str4)) {
		std::cout << str4 << "是回文字符串" << std::endl;
	}
	else {
		std::cout << str4 << "不是回文字符串" << std::endl;
	}
	//手写 strlen
	const char str5[] = "asfasfga";
	std::cout << "字符串长度为：" << MyStrlen(str5) << std::endl;

	//手写字符串复制的简化版
	char str6[] = "asgagege";
	char str7[100];
	MyStrcpy(str7, str6);
	std::cout << str7 << std::endl;
	return 0;
}

