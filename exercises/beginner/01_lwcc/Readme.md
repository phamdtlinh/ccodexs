## 1. Đếm số từ trong file ##

**Mô tả** : Xây dựng một công cụ dòng lệnh đọc một tệp văn bản và thống kê các thông số văn bản cơ bản.

**Yêu cầu:**
* Đếm tổng số dòng, số từ (phân cách bởi khoảng trắng) và tổng số ký tự.

* Xử lý lỗi nếu file không tồn tại hoặc không mở được.

**Kiến thức áp dụng:**

- **Kiến thức C:** fopen, getc, isspace, logic vòng lặp while.

- **Data Structure:** Buffer (mảng ký tự tạm thời).

- **Thuật toán:** Duyệt tuần tự (Linear Scan), Kỹ thuật cờ hiệu (Flag) để xác định trạng thái đang trong hay ngoài một từ.

**Phạm vi thực tế:** Thành phần cốt lõi của các trình soạn thảo văn bản như MS Word, Notepad++.

**Tên file mã nguồn:** lwcc.c (lines, words, chars counter)