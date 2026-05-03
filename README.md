🚀 README LEVEL PRO (copy nguyên vào README.md)
# 🎮 SS004 - Tetris Game Project (Nhóm 9)

<p align="center">
  <b>Đồ án cuối kỳ môn Kỹ năng nghề nghiệp (SS004) - UIT</b><br>
  Xây dựng trò chơi Tetris bằng C++ với quy trình làm việc nhóm chuyên nghiệp
</p>

---

## 📌 Tổng quan dự án

Dự án nhằm xây dựng lại trò chơi **Tetris kinh điển** bằng ngôn ngữ C++, đồng thời áp dụng quy trình phát triển phần mềm thực tế:

- Làm việc nhóm qua GitHub
- Quản lý công việc bằng Issues
- Code theo branch
- Merge bằng Pull Request

👉 Đây không chỉ là một game, mà là một **mini software project hoàn chỉnh**

---

## 🧠 Gameplay

Người chơi điều khiển các khối (Tetromino) rơi xuống bảng:

- Sắp xếp để tạo hàng đầy
- Hàng đầy sẽ bị xóa
- Game kết thúc khi khối chạm đỉnh

---

## 🎮 Điều khiển

| Phím | Chức năng |
|------|----------|
| A | Di chuyển trái |
| D | Di chuyển phải |
| X | Rơi nhanh |
| Q | Thoát game |

---

## 🧩 Các loại khối


I, O, T, S, Z, J, L


(📌 Có thể bổ sung hình minh họa sau)

---

## 🛠 Công nghệ sử dụng

| Thành phần | Công nghệ |
|------|--------|
| Ngôn ngữ | C++ |
| Thư viện | iostream, conio.h |
| Version Control | Git & GitHub |
| Tài liệu | Overleaf (LaTeX) |
| Giao tiếp | Slack |

---

## 📂 Cấu trúc project


SS004_Tetris_Project_Nhom9/
│
├── src/
│ ├── main.cpp
│ ├── block.cpp
│ ├── board.cpp
│ ├── game.cpp
│
├── README.md
└── .gitignore


---

## ⚙️ Cách chạy chương trình

### 🔹 Cách 1: IDE

- Mở project bằng Dev C++ / CodeBlocks
- Run file `main.cpp`

### 🔹 Cách 2: Terminal

```bash
g++ src/main.cpp -o tetris
./tetris
🔄 Quy trình phát triển
Issue → Branch → Code → Commit → Pull Request → Review → Merge
📌 Phân công nhiệm vụ
Thành viên	Vai trò
Trần Huỳnh Thiện	Project Manager / Core
Nguyễn Trần Ngọc Ngọc	Game logic
Nguyễn Chí Thành	removeLine
Đào Hoàng Huy	UI/UX
Phạm Hữu Tài	Rotate + Speed
