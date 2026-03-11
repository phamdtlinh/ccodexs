# Tên Repository: ccodex (tên đầy đủ: C Code Examples)
Repository này chứa các bài tập và ví dụ mẫu trong quá trình học C, chưa phải là toàn bộ nhưng là phần lớn, các bài được chia thư mục 1 cách ngẫu hứng

## 🚀 Quy trình Build & Run

Toàn bộ Binary sẽ được xuất ra thư mục `/bin` ở thư mục gốc để đảm bảo tính gọn gàng (thư mục `/bin` phải tự tạo trên local trước khi)

### Ví dụ
```bash
# Di chuyển đến thư mục bài tập
cd exercises/the_c_programing_language_kr/ch01/

# Biên dịch (Ví dụ bài 1.1)
gcc -Wall -Wextra -std=c11 ex1_1.c -o ../../../bin/ex1_1

# Thực thi từ thư mục bài tập
../../../bin/ex1_1
```
#### Hoặc tại thư mục gốc
```bash
# Biên dịch (Ví dụ ./simple/tree/tree.c)
gcc -Wall -Wextra -std=c11 ./simple/tree/tree.c -o ./bin/tree

# Thực thi từ thư mục gốc
./bin/tree
```

## Cấu trúc thư mục hiện tại:
```
./
├── bin
│   ├── recursive_function_debug
│   ├── tree
│   └── tree_debug
├── exercises
│   └── the_c_programing_language_kr
│       ├── ch01
│       │   └── Readme.md
│       ├── ch02
│       │   └── Readme.md
│       ├── ch03
│       │   └── Readme.md
│       ├── ch04
│       │   └── Readme.md
│       ├── ch05
│       │   └── Readme.md
│       ├── ch06
│       │   └── Readme.md
│       ├── ch07
│       │   └── Readme.md
│       └── ch08
│           └── Readme.md
├── LICENSE
├── README.md
├── recursion
│   └── recursive_functions.c
├── simple
│   ├── stack
│   │   ├── stack.c
│   │   └── stack.h
│   └── tree
│       ├── tree.c
│       └── tree.h
└── utilities
    └── random_integer_generators.c
```
