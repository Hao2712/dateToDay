#include <stdio.h>

// Hàm tính thứ trong tuần dựa trên ngày, tháng và năm
void getDayOfWeek(int day, int month, int year) {
    // Zeller's Congruence Algorithm
    if (month < 3) {
        month = month + 12;
        year--;
    }
    int k = year % 100; // 2024 % 100 = 24
    int j = year / 100; // 2024 / 100 = 20
    int dayOfWeek = (day + (13 * (month + 1) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    dayOfWeek = (dayOfWeek + 7) % 7; // Đảm bảo ngày trong tuần là dương

    // Mảng chứa tên các ngày trong tuần
    char *days[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};

    printf("Thu cua ngay nhap vao: %s", days[dayOfWeek]);
}

// Hàm kiểm tra năm nhuận
int isLeapYear(int year) {
    // Kiểm tra năm nhuận theo quy tắc
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // Năm chia hết cho 400 là năm nhuận
            } else {
                return 0; // Năm chia hết cho 100 nhưng không chia hết cho 400 không phải là năm nhuận
            }
        } else {
            return 1; // Năm chia hết cho 4 nhưng không chia hết cho 100 là năm nhuận
        }
    } else {
        return 0; // Năm không chia hết cho 4 không phải là năm nhuận
    }
}

int main() {
    int day, month, year;
    int leap;
    
    // Nhập ngày, tháng và năm từ người dùng
    printf("Nhap ngay (1-31): ");
    scanf("%d", &day);
    printf("Nhap thang (1-12): ");
    scanf("%d", &month);
    printf("Nhap nam: ");
    scanf("%d", &year);

    leap = isLeapYear(year);

    // Kiểm tra ngày hợp lệ
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Nhap sai du kien!!!\n");
        return 0;
    }
    if (day > 29 && month == 2) {
        printf("Thang 2 khong co ngay 30, 31!!!");
        return 0;
    } else if (day == 29 && month == 2 && leap == 0) {
        printf("Khong phai nam nhuan!!!");
        return 0;
    }

    getDayOfWeek(day, month, year);
    
    return 0;
}
