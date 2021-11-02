### THƯ VIỆN DATETIME HỖ TRỢ TƯƠNG TÁC VỚI KIỂU DỮ LIỆU DATE

#### 1. SỬ DỤNG
##### 1.1. ĐỊNH DẠNG
- Format kiểu dữ liệu là: dd-mm-yyyy hh:mm:ss
- `hh:mm:ss` không cần thiết phải có
- Ví dụ: 30-04-2002
- Ví dụ: 30-04-2002 12:00:01
##### 1.2. KHỞI TẠO
`
    DATE A = "30-04-2002 12:00:01";
    DATE B("30-04-2002");
    DATE C = A;
`
##### 1.3. PHƯƠNG THỨC
- `getDay()`: Trả về số ngày của đối tượng (01 - 31).
- `getMonth()`: Trả về số tháng của đối tượng (01 - 12).
- `getYear()`: Trả về số năm của đối tượng.
- `getHour()`: Trả về số giờ của đối tượng (00 - 23).
- `getMinute()`: Trả về số phút của đối tượng (00 - 59).
- `getSecond()`: Trả về số giấy của đối tượng (00 - 59).

- `getCurrentDate()`: Trả về đối tượng giữ thông tin thời gian hiện tại.
- `DATEDIFF(const Date &A, const Date &B)`: Trả về khoảng cách giữa 2 ngày A và B.
- `isValidDate()`: Kiểm tra kiểu ngày có hợp lệ.
- `dayOfMonth(const int &month, const int &year)`: Trả về số ngày của tháng của một năm.

- Các phép gán, so sánh (`==, !=, >, <, >=, <=`).