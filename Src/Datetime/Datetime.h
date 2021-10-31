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
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getMinute();
		int getSecond();
		bool isLeapYear(); // Kiểm tra năm nhuận
		bool isValidDate();
		bool isValidHour();
		static Date getCurrentDate();
		void toDate(const char*); // Convert string sang Date

		const Date& operator=(const Date&);
		friend bool operator>(const Date&, const Date&);
		friend bool operator<(const Date&, const Date&);
		friend bool operator>=(const Date&, const Date&);
		friend bool operator<=(const Date&, const Date&);
		friend istream& operator>>(istream&, Date&);
		friend ostream& operator<<(ostream&, const Date&);
};