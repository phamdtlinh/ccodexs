
# K&R C Solutions - Chương 1: Giới thiệu tổng quan

Thư mục này chứa các lời giải bài tập tham khảo của Chương 1 từ cuốn sách *The C Programming Language (2nd Edition)*. Toàn bộ mã nguồn được viết theo tiêu chuẩn **C11/C17** (Modern C).

## 📌 Mục tiêu học tập
* Làm quen với cấu trúc tối giản của một chương trình hệ thống.
* Hiểu cơ chế Standard I/O (getchar/putchar).
* Quản lý trạng thái thông qua các biến cờ (flags).

## 📊 Danh sách bài tập & Tiến độ

| Bài tập | Tiêu đề | File | Trang | Độ khó | Trạng thái |
| :---: | :--- | :--- | :---: | :---: | :---: |
| **1.1** | Hello, World | [`ex_1_1.c`](./ex_1_1.c) | 5 | 1/10 |🚧|
| **1.2** | Fahrenheit - Celsius | [`ex_1_2.c`](./ex_1_2.c) | 13 | 2/10 |🚧|
| **1.3** | Word Counting | [`ex_1_3.c`](./ex_1_3.c) | 20 | 4/10 |🚧|
| **1.4** | Histogram Độ dài từ | [`ex_1_4.c`](./ex_1_4.c) | 24 | 6/10 |🚧|
Danh sách trạng thái:
✅: Đã xong, 🚧 Đang làm, 📅 Chưa làm

---

## 📚 Chi tiết các Bài tập

### Bài 1.1: Hello, World (Trang 5)
* **Độ khó:** 1/10
* **Kiến thức:** Tiền xử lý `#include`, hàm `printf`, chuỗi ký tự.
* **Diễn giải:** Làm quen với môi trường biên dịch và cấu trúc hàm `main`.
* **Yêu cầu chi tiết:** 1. In dòng chữ "hello, world".
    2. Thử nghiệm bỏ các thành phần bắt buộc (dấu `;`, ngoặc) để xem lỗi compiler.
* **Ví dụ:**
    * **Input:** (None)
    * **Output:** `hello, world`

### Bài 1.2: Fahrenheit - Celsius (Trang 13)
* **Độ khó:** 2/10
* **Kiến thức:** Vòng lặp `for`, toán tử số học, hằng số `#define`, định dạng `%f`.
* **Diễn giải:** Học cách xử lý số thực và định dạng bảng biểu trong C.
* **Yêu cầu chi tiết:** In bảng chuyển đổi từ độ F sang độ C từ 300 xuống 0, bước nhảy 20. Phải sử dụng hằng số cho các giá trị Upper, Lower, Step.
* **Ví dụ:**
    * **Output:**
      ```text
      300  148.9
      280  137.8
      ...
      0    -17.8
      ```

### Bài 1.3: Bộ đếm từ - Word Counting (Trang 20)
* **Độ khó:** 4/10
* **Kiến thức:** `getchar()`, toán tử logic `&&` / `||`, biến trạng thái (`stdbool.h`).
* **Diễn giải:** Bài toán phân tích cú pháp (parsing) văn bản cơ bản.
* **Yêu cầu chi tiết:** Đếm dòng, từ và ký tự. Xử lý chính xác các trường hợp nhiều dấu cách liên tiếp.
* **Ví dụ:**
    * **Input:** `Hoc C   rat \n thu vi`
    * **Output:** `Dòng: 2, Từ: 5, Ký tự: 23`

### Bài 1.4: Biểu đồ tần suất (Trang 24)
* **Độ khó:** 6/10
* **Kiến thức:** Mảng (Arrays), vòng lặp lồng nhau, xử lý ký tự.
* **Diễn giải:** Trực quan hóa dữ liệu bằng các ký tự ASCII (biểu đồ thanh nằm ngang).
* **Yêu cầu chi tiết:** Vẽ biểu đồ thể hiện độ dài của các từ. Các từ dài hơn kích thước mảng dự định được gom vào nhóm cuối.
* **Ví dụ:**
    * **Input:** `Meo con thich an ca`
    * **Output:**
      ```text
      3: ***
      5: *****
      2: **
      ```

---

## 🚀 Quy trình Build & Run

Toàn bộ Binary sẽ được xuất ra thư mục `/bin` ở root để đảm bảo tính gọn gàng.

```bash
# Di chuyển đến thư mục bài tập
cd exercises/the_c_programing_language_kr/ch01/

# Biên dịch (Ví dụ bài 1.1)
gcc -Wall -Wextra -std=c11 ex1_1.c -o ../../../bin/ex1_1

# Thực thi từ thư mục bài tập
../../../bin/ex1_1
```

## 💡 Ghi chú Modern C
* Luôn sử dụng `int main(void)` để tường minh.
* Sử dụng `<stdbool.h>` cho các biến logic.
* Sử dụng `size_t` cho các chỉ số mảng và biến đếm kích thước.
* Nội dung được tạo bởi Gemini, có chỉnh sửa cho phù hợp
