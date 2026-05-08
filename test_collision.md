# Test Collision System

Người thực hiện: Ngọc

## Mục tiêu kiểm thử

Kiểm tra hệ thống va chạm của game Tetris, bao gồm va chạm với tường trái, tường phải, đáy màn hình và các block đã cố định trên board.

## Các trường hợp kiểm thử

| STT | Tình huống kiểm thử | Thao tác | Kết quả mong đợi | Kết quả thực tế |
|---|---|---|---|---|
| 1 | Block chạm tường trái | Nhấn phím A liên tục | Block không đi xuyên qua viền trái | Đạt |
| 2 | Block chạm tường phải | Nhấn phím D liên tục | Block không đi xuyên qua viền phải | Đạt |
| 3 | Block rơi xuống đáy | Không thao tác, để block tự rơi | Block dừng lại khi chạm đáy | Đạt |
| 4 | Block chạm block khác | Cho nhiều block rơi chồng lên nhau | Block mới dừng lại khi chạm block cũ | Đạt |
| 5 | Block rơi nhanh | Nhấn phím X nhiều lần | Block rơi nhanh nhưng không xuyên qua đáy | Đạt |

## Nhận xét

Hàm `canMove()` đã kiểm tra được các va chạm cơ bản giữa block với viền board và các block đã tồn tại. Qua kiểm thử, hệ thống va chạm hoạt động ổn định ở mức yêu cầu của bài tập nhóm.
