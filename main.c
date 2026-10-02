#include <stdio.h>
#define MAX_SIZE 50

int main(void) {
    int tickets[MAX_SIZE] = {85, 120, 60, 150, 95};
	int n = 5;
	int i;
    int choice;
    int loop = 1;
    int value;
    int pos;
    while (loop == 1) {
        printf("=====================================================\n");
        printf("     CHUONG TRINH QUAN LY VE SO BAN RA STARCINEMA    \n");
        printf("=====================================================\n");
        printf("1. Them so ve ban ra\n");
        printf("2. Sua so ve ban ra\n");
        printf("3. Xoa so ve ban ra\n");
        printf("4. Tim kiem so ve ban ra\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");

        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Them so ve\n");
                printf("Cac phan tu dang co trong mang: \n");
                for (i = 0; i < n; i++) {
                    printf("%d ", tickets[i]);
                }
                if (n == MAX_SIZE) {
                    printf("Mang da day, khong the them\n");
                    break;
                }
           
                printf("\nMoi ban nhap vao gia tri ve so can them: ");
                scanf("%d", &value);
             
                if (value < 0) {
                    printf("So luong ve so khong hop le\n");
                    break;
                }
            
                printf("Moi ban nhap vao vi tri muon chen (1 - %d): ", n + 1);
                scanf("%d", &pos);

 
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le\n");
                    break;
                }

                for (i = n; i >= pos; i--) {
                    tickets[i] = tickets[i - 1];
                }
                tickets[pos - 1] = value;
                n++;
                printf("Chen thanh cong\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", tickets[i]);
                }
                break;
            case 2:
                printf("Sua ve so\n");
                int newValue;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                	printf("Vi tri khong hop le!\n");
				}
				else {
					printf("Nhap gia tri moi: ");
					scanf("%d", &newValue);
					if (newValue < 0) {
						printf("So ve ban ra khong hop le!\n");
					} else {
						tickets[pos-1] = newValue;
						printf("Ket qua: [");
						for (i = 0; i < n; i++) {
							printf("%d", tickets[i]);
							if (i < n - 1) {
								printf(", ");
							}
						}
						printf("]\n");
					}
				}
                break;
            case 3:
                printf("Xoa ve so\n");
                if (n == 0) {
                	printf("Mang rong, khong the xoa!\n");
				} else {
					printf("Nhap vi tri can xoa: ");
					scanf("%d", &pos);
					if (pos < 1 || pos > n) {
						printf("Vi tri xoa khong hop le!\n");
					} else {
						for (i = pos - 1; i < n; i++) {
							tickets[i] = tickets[i + 1];
						}
						n--;
						printf("Ket qua: [");
						for (i = 0; i < n; i++) {
							printf("%d", tickets[i]);
							if (i < n -1) {
								printf(", ");
							}
						}
						printf("]\n");
					}
				}
                break;
            case 4:
                printf("Tim kiem ve so\n");
                int target;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                int count = 0;
                int found[MAX_SIZE];
                for (i = 0; i < n; i++) {
                	if (tickets[i] == target) {
                		found[count] = i + 1;
                		count++;
					}
				}
				if (count == 0) {
					printf("Khong tim thay gia tri trong mang!\n");
				} else {
					printf("\n==========================================\n");
					printf("KET QUA TIM KIEM\n");
					printf("\n==========================================\n");
					printf("Gia tri can tim: %d\n", target);
					printf("Vi tri		   : ");
				}
				printf("\nSo lan xuat hien: %d\n", count);
				
                break;
            case 0:
                printf("Thoat\n");
                loop = 0;
                break;
            default:
                printf("Lua chon khong hop le, vui long nhap lai\n");
                break;
        }
    }
    return 0;
}
