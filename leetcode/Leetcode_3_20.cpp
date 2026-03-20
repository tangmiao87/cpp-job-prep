#include<iostream>
#include<string>
#include <cstring>

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

bool VerifyPalindrome(const char* str) {
	std::string temp;
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		bool is_digit = (str[i] >= '0' && str[i] <= '9');
		bool is_upper = (str[i] >= 'A' && str[i] <= 'Z');
		bool is_lower = (str[i] >= 'a' && str[i] <= 'z');
		if (is_digit||is_lower) {
			temp += str[i];
		}
		else if (is_upper) {
			temp += str[i] - 'A' + 'a';
		}
	}
	return Palindrome(temp);
}

int endLength(const char* str) {
	int str_len = strlen(str);
	if (str_len == 0) return 0;
	int len = 0;
	while (str_len > 0 && str[str_len - 1] == ' ') {//注意判断先后顺序
		str_len--;
	}
	if (str_len == 0) return 0;
	while (str_len > 0 && str[str_len - 1] != ' ') {//注意越界
		str_len--;
		len++;
	}
	return len;
}

int main() {
	//给你一个字符串，只保留字母和数字，忽略大小写，判断它是不是回文串。
	char str1[] = "A man, a plan, a canal: Panama";
	if (VerifyPalindrome(str1)) {
		std::cout << str1 << "是回文串" << std::endl;
	}
	else {
		std::cout << str1 << "不是回文串" << std::endl;
	}

	//给你一个字符串，返回最后一个单词的长度。

	char str2[] = "    ";
	std::cout << str2 << "最后一个单词的长度为：" << endLength(str2) << std::endl;
	char str3[] = "Hello World";
	std::cout << str3 << "最后一个单词的长度为：" << endLength(str3) << std::endl;
	char str4[] = " fly me to the moon ";
	std::cout << str4 << "最后一个单词的长度为：" << endLength(str4) << std::endl;
	char str5[] = "Hello";
	std::cout << str5 << "最后一个单词的长度为：" << endLength(str5) << std::endl;

	return 0;
}

