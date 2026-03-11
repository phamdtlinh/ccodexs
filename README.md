# Tên Repository: ccodex (tên đầy đủ: C Code Examples)
Repository này chứa các bài tập và ví dụ mẫu trong quá trình học C, chưa phải là toàn bộ nhưng là phần lớn, các bài được chia thư mục 1 cách ngẫu hứng

## 🚀 Quy trình Build & Run

Toàn bộ Binary sẽ được xuất ra thư mục `/bin` ở root để đảm bảo tính gọn gàng (thư mục `/bin` phải tự tạo trên local trước khi)

### Ví dụ
```bash
# Di chuyển đến thư mục bài tập
cd exercises/the_c_programing_language_kr/ch01/

# Biên dịch (Ví dụ bài 1.1)
gcc -Wall -Wextra -std=c11 ex1_1.c -o ../../../bin/ex1_1

# Thực thi từ thư mục bài tập
../../../bin/ex1_1
```
