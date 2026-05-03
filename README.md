# 🎮 SS004 - Tetris Game Project (Nhóm 9)

## 📌 Giới thiệu
Đây là đồ án cuối kỳ môn **Kỹ năng nghề nghiệp (SS004)** tại UIT.  
Nhóm thực hiện xây dựng trò chơi **Tetris** bằng ngôn ngữ C++.

Mục tiêu của dự án:
- Áp dụng kỹ năng làm việc nhóm
- Sử dụng Git/GitHub trong phát triển phần mềm
- Xây dựng một trò chơi hoàn chỉnh từ cơ bản

---

## 👨‍💻 Thành viên nhóm

| MSSV | Họ tên |
|------|------|
| 23730034 | Nguyễn Trần Ngọc Ngọc |
| 23730050 | Trần Huỳnh Thiện |
| 24730179 | Nguyễn Chí Thành |
| 25730115 | Đào Hoàng Huy |
| 25730142 | Phạm Hữu Tài |

---

## 🛠 Công nghệ sử dụng

- Ngôn ngữ: **C++**
- Thư viện:
  - `<iostream>`
  - `<conio.h>`
- Công cụ:
  - GitHub (quản lý mã nguồn)
  - Overleaf (viết báo cáo)
  - Slack (trao đổi nhóm)

---

## 🎯 Chức năng chính

- Hiển thị bảng game (board)
- Khối rơi tự động
- Di chuyển trái/phải/xuống
- Xóa dòng (removeLine)
- Xoay khối (đang phát triển)
- Tăng tốc độ theo thời gian

---

## 🎮 Điều khiển

| Phím | Chức năng |
|------|----------|
| A | Di chuyển trái |
| D | Di chuyển phải |
| X | Rơi nhanh |
| Q | Thoát game |

---

## 📂 Cấu trúc thư mục

```bash
src/
 ├── main.cpp
 ├── block.cpp
 ├── board.cpp
 ├── game.cpp
