README hiện tại của bạn đã khá ổn rồi, nhưng đúng là:

* thiếu thành viên Thúy Vương,
* một vài vai trò chưa sát thực tế,
* có vài chỗ hơi “template”,
* chưa thể hiện rõ quá trình teamwork thật,
* và chưa phản ánh đúng gameplay/code hiện tại.

Mình viết lại theo hướng:

* nhìn chuyên nghiệp kiểu GitHub thật,
* bám sát đúng project hiện tại,
* đúng workflow nhóm đã làm,
* đúng tính năng thật sự đã có,
* và vẫn đẹp để thầy mở repo lên thấy “có đầu tư”.

````md
# 🎮 SS004 - TETRIS GAME PROJECT (NHÓM 09)

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B)
![UIT](https://img.shields.io/badge/UIT-SS004-success?style=for-the-badge)
![GitHub](https://img.shields.io/badge/GitHub-Workflow-orange?style=for-the-badge&logo=github)
![Git](https://img.shields.io/badge/Git-Branching-red?style=for-the-badge&logo=git)
![Overleaf](https://img.shields.io/badge/LaTeX-Overleaf-green?style=for-the-badge&logo=overleaf)
![Slack](https://img.shields.io/badge/Slack-Teamwork-purple?style=for-the-badge&logo=slack)

<br>

# 🕹️ ĐỒ ÁN CUỐI KỲ MÔN KỸ NĂNG NGHỀ NGHIỆP (SS004)

### Xây dựng trò chơi Tetris bằng C++ kết hợp quy trình làm việc nhóm thực tế

</div>

---

# 📌 Giới thiệu dự án

Dự án được thực hiện nhằm xây dựng lại trò chơi **Tetris cổ điển** bằng ngôn ngữ **C++** trên môi trường console.

Bên cạnh việc phát triển gameplay, nhóm còn áp dụng đầy đủ quy trình làm việc nhóm trong phát triển phần mềm thực tế như:

- 📂 Quản lý source code bằng GitHub
- 🌿 Làm việc theo branch
- 🔀 Merge code bằng Pull Request
- 📋 Quản lý task và tiến độ nhóm
- 💬 Trao đổi công việc qua Slack
- 📝 Viết báo cáo bằng LaTeX trên Overleaf

Mục tiêu của đồ án không chỉ là tạo ra một game có thể chơi được mà còn giúp các thành viên:
- làm quen workflow Git thực tế,
- phối hợp source code,
- quản lý task,
- và rèn luyện kỹ năng teamwork trong môi trường software project.

---

# 🎯 Mục tiêu dự án

- Xây dựng gameplay Tetris cơ bản bằng C++
- Áp dụng lập trình hướng đối tượng (OOP)
- Thực hành quy trình Git workflow
- Rèn luyện kỹ năng teamwork
- Làm quen với merge branch và xử lý conflict
- Viết tài liệu kỹ thuật bằng LaTeX
- Hoàn thiện quy trình làm việc nhóm theo yêu cầu môn học

---

# 🧩 Gameplay

Người chơi điều khiển các khối Tetromino rơi từ trên xuống và sắp xếp chúng thành các hàng ngang hoàn chỉnh.

Khi một hàng được lấp đầy:
- hàng đó sẽ bị xóa,
- các block phía trên sẽ rơi xuống,
- và tốc độ game sẽ tăng dần theo thời gian.

Game sẽ kết thúc khi các khối chạm đến đỉnh board.

---

# 🎮 Điều khiển

| Phím | Chức năng |
|------|------------|
| A | Di chuyển sang trái |
| D | Di chuyển sang phải |
| X | Rơi nhanh |
| W | Xoay block |
| Q | Thoát game |

---

# ✨ Các tính năng đã triển khai

## ✅ Gameplay cơ bản
- Block rơi tự động
- Random block
- Collision với tường
- Collision giữa các block
- Kiểm tra game over

## ✅ Remove Line
- Tự động kiểm tra hàng đầy
- Xóa dòng hoàn chỉnh
- Dồn block phía trên xuống

## ✅ Tăng độ khó
- Tăng tốc độ game sau khi xóa line
- Gameplay nhanh dần theo thời gian

## ✅ OOP
- Sử dụng class `Block`
- Quản lý block bằng object
- Tách prototype block và currentShape

## ✅ Gameplay Improvement
- Hiển thị Next Block
- Hiển thị Score
- Hiển thị tổng số line đã xóa
- Wall-kick đơn giản khi xoay block
- Input realtime bằng `GetAsyncKeyState`

## ✅ Git Workflow
- Làm việc theo branch
- Pull Request
- Merge code
- Commit history
- Contributor tracking

---

# 🏗️ Cấu trúc dự án

```bash
SS004_Tetris_Project_Nhom9
│
├── .vscode/
├── src/
│
├── main.cpp
├── README.md
├── test_collision.md
└── .gitignore
````

---

# 👥 Thành viên nhóm

| Thành viên            | Vai trò                                                         |
| --------------------- | --------------------------------------------------------------- |
| Trần Huỳnh Thiện      | Project Manager, Gameplay Logic, Git Workflow, Tổng hợp báo cáo |
| Đào Hoàng Huy         | Gameplay Development, UI Board, Rendering, Logic hỗ trợ         |
| Nguyễn Trần Ngọc Ngọc | Gameplay Support, Test game, Thiết kế slide                     |
| Phan Thị Thúy Vương   | Test gameplay, Hỗ trợ tài liệu, Thuyết trình                    |

---

# 🔧 Công nghệ và công cụ sử dụng

| Công cụ      | Mục đích             |
| ------------ | -------------------- |
| C++          | Lập trình game       |
| GitHub       | Quản lý source code  |
| Git Branch   | Làm việc song song   |
| Pull Request | Merge và review code |
| Slack        | Trao đổi công việc   |
| Slack Canvas | Quản lý task         |
| Overleaf     | Viết báo cáo LaTeX   |
| VS Code      | Coding và debug      |

---

# 📈 Workflow làm việc nhóm

Nhóm áp dụng mô hình workflow thực tế:

```text
Task → Branch → Coding → Commit → Pull Request → Review → Merge
```

Quy trình làm việc:

* Mỗi thành viên nhận task riêng
* Code trên branch riêng
* Commit thường xuyên
* Push lên GitHub
* Tạo Pull Request
* Merge vào branch main sau khi kiểm tra

Trong quá trình thực hiện, nhóm đã:

* xử lý merge conflict,
* chia lại công việc,
* debug gameplay,
* và phối hợp chỉnh sửa source code trực tiếp trên GitHub.

---

# 🧪 Quá trình kiểm thử

Gameplay được test nhiều lần để kiểm tra:

* Collision
* Rotation
* Remove line
* Input realtime
* Game over
* Speed scaling

Các lỗi được trao đổi và debug thông qua Slack trước khi cập nhật lên GitHub.

---

# 🚀 Hướng phát triển trong tương lai

Nếu tiếp tục phát triển, game có thể mở rộng thêm:

* 🔊 Âm thanh
* 🎨 Theme màu sắc
* 🏆 High score
* 💾 Lưu điểm bằng file/database
* 🌐 Multiplayer local
* ✨ Hiệu ứng animation
* 📱 Giao diện đồ họa GUI

---

# 📚 Báo cáo dự án

Báo cáo được thực hiện bằng:

* LaTeX
* Overleaf
* PDF duy nhất theo yêu cầu môn học

Bao gồm:

* Hợp đồng nhóm
* Link công cụ làm việc
* Hướng dẫn chơi game
* Tài liệu kỹ thuật
* Mô tả quá trình teamwork
* Các kỹ năng áp dụng
* Đánh giá thực hiện hợp đồng nhóm

---

# 🏫 Thông tin môn học

| Nội dung   | Thông tin                                     |
| ---------- | --------------------------------------------- |
| Môn học    | Kỹ năng nghề nghiệp (SS004)                   |
| Trường     | Đại học Công nghệ Thông tin - ĐHQG TP.HCM     |
| Giảng viên | [toannv@uit.edu.vn](mailto:toannv@uit.edu.vn) |

---

<div align="center">

# ⭐ THANK YOU FOR VISITING OUR PROJECT ⭐

### 🎮 “Simple gameplay — Real teamwork experience”

</div>
```
