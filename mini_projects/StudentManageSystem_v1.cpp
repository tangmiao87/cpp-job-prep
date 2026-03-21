#include<iostream>
#include<string>
#include<vector>
#include <limits>

struct Student {
	std::string name;
	int age;
	int score;
};

struct StudentSystem {
	std::vector<Student> v1;
};

void Menu() {
	std::cout << "1.添加学生" << std::endl;
	std::cout << "2.显示所有学生" << std::endl;
	std::cout << "3.查找学生" << std::endl;
	std::cout << "4.删除学生" << std::endl;
	std::cout << "5.按成绩排序" << std::endl;
	std::cout << "0.退出系统" << std::endl;
}

std::string trimWhiteSpace(const std::string& str) {
	if (str.empty()) return "";
	int start = 0, end = str.size() - 1;
	while (start < str.size() && str[start] == ' ') start++;
	while (end >= 0 && str[end] == ' ')end--;
	if (start > end)return "";

	std::string result = "";
	for (int i = start; i <= end; i++)result += str[i];
	return result;
}

void addStudent(StudentSystem& s) {
	std::string name;
	int age;
	int score;
	std::cout << "请输入学生姓名：";
	while (true) {
		std::getline(std::cin >> std::ws, name);
		std::string trimmedName = trimWhiteSpace(name);
		if (trimmedName.empty()) {
			std::cout << "姓名不能为空，请重新输入：" << std::endl;
			continue;
		}
		if (trimmedName.size() >= 50) {
			std::cout << "姓名字符在1-50之间，请重新输入：" << std::endl;
			continue;
		}
		name = trimmedName;
		break;
	}
	
	std::cout << "请输入学生年龄：";
	while (true) {
		if (std::cin >> age && age >= 0 && age <= 150) {
			break;
		}
		else {
			std::cout << "请输入0-150的整数，请重新输入：";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	std::cout << "请输入学生分数：";
	while (true) {
		if (std::cin >> score && score >= 0 && score <= 750) {
			break;
		}
		else {
			std::cout << "分数在0-750之间，请重新输入：";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	s.v1.emplace_back(Student{ name,age,score });
	std::cout << "添加成功。" << std::endl;
}

void showStudents(const StudentSystem& s) {
	if (s.v1.size() == 0) {
		std::cout << "系统中没有学生，请先进行添加。" << std::endl;
		return;
	}
	std::cout << "学生系统总人数：" << s.v1.size() << std::endl;
	for (int i = 0; i < s.v1.size(); i++) {
		std::cout << "姓名：" << s.v1[i].name
			<< "\t年龄：" << s.v1[i].age
			<< "\t分数：" << s.v1[i].score << std::endl;
	}
}

void findStudent(const StudentSystem& s) {
	if (s.v1.size() == 0) {
		std::cout << "系统中没有学生，请先进行添加。" << std::endl;
		return;
	}
	int num = 0;
	std::cout << "1.按姓名查找" << std::endl;
	std::cout << "2.按年龄查找" << std::endl;
	std::cout << "3.按分数查找" << std::endl;
	do {
		std::cout << "请输入查找方式：";
		std::cin >> num;
	} while (num < 1 || num>3);
	std::string name;
	int x;
	int count = 0;
	switch (num) {
	case 1: {
		std::cout << "请输入学生姓名：";
		while (true) {
			std::getline(std::cin >> std::ws, name);
			std::string trimmedName = trimWhiteSpace(name);
			if (trimmedName.empty()) {
				std::cout << "姓名不能为空，请重新输入：" << std::endl;
				continue;
			}
			if (trimmedName.size() >= 50) {
				std::cout << "姓名字符在1-50之间，请重新输入：" << std::endl;
				continue;
			}
			name = trimmedName;
			break;
		}
		for (std::vector<Student>::const_iterator it = s.v1.begin(); it != s.v1.end(); it++) {
			if ((*it).name == name) {
				std::cout << "姓名：" << (*it).name
					<< "\t年龄：" << it->age
					<< "\t分数：" << it->score << std::endl;
				count++;
			}
		}
		if (count == 0) {
			std::cout << "查无此人" << std::endl;
		}
	}
		break;
	case 2: {
		std::cout << "请输入学生年龄：";
		while (true) {
			if (std::cin >> x && x >= 0 && x <= 150) {
				break;
			}
			else {
				std::cout << "请输入0-150的整数，请重新输入：";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		for (const Student& stu:s.v1) {
			if (stu.age == x) {
				std::cout << "姓名：" << stu.name
					<< "\t年龄：" << stu.age
					<< "\t分数：" << stu.score << std::endl;
				count++;
			}
		}
		if (count == 0) {
			std::cout << "查无此人" << std::endl;
		}
	}
		break;
	case 3: {
		std::cout << "请输入学生分数：";
		while (true) {
			if (std::cin >> x && x >= 0 && x <= 750) {
				break;
			}
			else {
				std::cout << "分数在0-750之间，请重新输入：";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		for (const Student& stu:s.v1) {
			if (stu.score == x) {
				std::cout << "姓名：" << stu.name
					<< "\t年龄：" << stu.age
					<< "\t分数：" << stu.score << std::endl;
				count++;
			}
		}
		if (count == 0) {
			std::cout << "查无此人" << std::endl;
		}
	}
		break;
	}
}

void deleteStudent(StudentSystem& s) {
	if (s.v1.size() == 0) {
		std::cout << "系统中没有学生，请先进行添加。" << std::endl;
		return;
	}
	std::string name;
	std::cout << "请输入学生姓名：";
	while (true) {
		std::getline(std::cin >> std::ws, name);
		std::string trimmedName = trimWhiteSpace(name);
		if (trimmedName.empty()) {
			std::cout << "姓名不能为空，请重新输入：" << std::endl;
			continue;
		}
		if (trimmedName.size() >= 50) {
			std::cout << "姓名字符在1-50之间，请重新输入：" << std::endl;
			continue;
		}
		name = trimmedName;
		break;
	}
	for (std::vector<Student>::iterator it = s.v1.begin(); it != s.v1.end(); it++) {
		if ((*it).name == name) {
			s.v1.erase(it);
			std::cout << "已将" << name << "删除." << std::endl;
			return;
		}
	}
	std::cout << "查无此人" << std::endl;
}

void sortScore(StudentSystem& s) {
	if (s.v1.size() < 2) {
		std::cout << "学生数量不足，无需排序。" << std::endl;
		return;
	}
	for (int i = 0; i < s.v1.size() -1;i++) {
		for (int j = 0; j < s.v1.size() - 1 - i;j++) {
			if (s.v1[j].score < s.v1[j + 1].score) {
				Student temp = s.v1[j];
				s.v1[j] = s.v1[j + 1];
				s.v1[j + 1] = temp;
			}
		}
	}
	std::cout << "排序完成。" << std::endl;
	showStudents(s);
}


int main() {
	StudentSystem s1;
	std::cout << "学生系统已成功创建。" << std::endl;
	int input = 0;
	while (true) {
		Menu();
		while (true) {
			std::cout << "请输入数字：";
			if (std::cin >> input) {
				break;
			}
			else {
				std::cout << "错误，请输入有效数字。" << std::endl;
				std::cin.clear(); //重置cin的错误状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空输入缓冲区的错误内容
			}
		}
		switch (input) {
		case 1:
			addStudent(s1);
			break;
		case 2:
			showStudents(s1);
			break;
		case 3:
			findStudent(s1);
			break;
		case 4:
			deleteStudent(s1);
			break;
		case 5:
			sortScore(s1);
			break;
		case 0:
			std::cout << "欢迎下次使用学生系统。再见！" << std::endl;
			return 0;
			break;
		default:
			std::cout << "输入有误，请重新输入。" << std::endl;
			break;
		}
	}
	return 0;
}

