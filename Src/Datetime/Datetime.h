#ifndef DATETIME_H
#define DATETIME_H
#include <iostream>
using namespace std;
class Date{
	private:
		int day, month, year;
		int hour, minute, second;
	public:
		Date(const int& = -1, const int& = -1, const int& = -1, const int& = -1, const int& = -1, const int& = -1);
		Date(const char*);
		Date(const Date&);
		// Getter
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getMinute();
		int getSecond();

		bool isLeapYear(); // Kiểm tra năm nhuận
		bool isValidDate();
		bool isValidHour();
		
		string toString();
		static Date getCurrentDate();
		static bool compareDate(const Date&, const Date&);
		static bool compareHour(const Date&, const Date&);
		static int dayOfMonth(const int&, const int&);
		static int DATEDIFF(const Date&, const Date&);
		void toDate(const char*); // Convert string sang Date

		const Date& operator=(const Date&);
		friend bool operator==(const Date&, const Date&);
		friend bool operator!=(const Date&, const Date&);
		friend bool operator>(const Date&, const Date&);
		friend bool operator<(const Date&, const Date&);
		friend bool operator>=(const Date&, const Date&);
		friend bool operator<=(const Date&, const Date&);
		friend istream& operator>>(istream&, Date&);
		friend ostream& operator<<(ostream&, const Date&);
};
#endif