#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#define MAX_STOCK_NAME_LEN 1280

char* csvWrap(char* str);
double method01(double standard_top, double standard_down, int profit, int stoploss, double** data, int num);

int main() {
	std::string str_buf;
	std::fstream fs;
	printf("분석할 주식 이름: ");
	size_t size = sizeof(char) * MAX_STOCK_NAME_LEN;
	char* stock = (char*)malloc(size);
	scanf_s("%[^\n]s", stock, size);
	stock = csvWrap(stock);
	printf("분석할 자료 개수: ");
	int num;
	scanf_s("%d", &num);
	int temp = 0;
	size_t size_data = sizeof(double*) * num;
	size_t size_data_single = sizeof(double) * 8;
	double** data = (double**)malloc(size_data);
	if (data == NULL) {
		exit(1);
	}
	for (int i = 0; i < num; i++) {
		data[i] = (double*)malloc(size_data_single);
		if (data[i] == NULL) {
			exit(1);
		}
	}
	fs.open(stock, std::ios::in);
	for (int i = 0; i < 13; i++) {
		getline(fs, str_buf, ',');
	}
	temp = 0;
	while (!fs.eof()) {
		getline(fs, str_buf, ',');
		for (int i = 0; i < 8; i++) {
			getline(fs, str_buf, ',');
			data[temp][i] = atof(str_buf.c_str());
		}
		getline(fs, str_buf, ',');
		temp++;
		if (temp == num) {
			break;
		}
	}
	fs.close();
	

}

char* csvWrap(char* str) {
	//return str;
	size_t size = sizeof(char) * (strlen(str) + 7);
	char* result = (char*)malloc(size);
	if (result == NULL) {
		exit(1);
	}
	strcpy_s(result, size, "");
	strcat_s(result, size, str);
	strcat_s(result, size, ".csv");
	return result;
}

double method01(double standard_top, double standard_down, int profit, int stoploss, double** data, int num) {
	int temp = num - 1;
	bool macdBigger = (data[temp][6] > 0) ? true : false;

}