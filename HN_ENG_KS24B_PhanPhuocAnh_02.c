#include <stdio.h>
int PerfectNumber(int n){
    int sum = 0;
    for (int i=1;i<=n/2; i++) {
        if (n%i== 0) {
            sum += i;
        }
    }
    return (sum==n&&n!= 0);
}
int secSmallest(int arr[], int n) {
    int smallest=arr[0], secSmall = -1;
    for (int i=1;i<n; i++) {
        if (arr[i] < smallest) {
            secSmall = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && (secSmall == -1 || arr[i] < secSmall)) {
            secSmall = arr[i];
        }
    }
    return secSmall;
}

int main() {
    int choose, position;
    int n;
    int arr[100];
    int check = -1;
    int count;
    int index, value;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    do {
        printf("\tMENU:\n");
        printf("1: In ra cac gia tri phan tu trong mang\n");
        printf("2: Dem so luong cac so hoan hao trong mang\n");
        printf("3: Tim gia tri nho thu hai co trong mang\n");
        printf("4: Them phan tu ngau nhien vao trong mang\n");
        printf("5: Xoa phan tu tai mot vi tri cu the\n");
        printf("6: Sap xep mang theo thu tu tang dan\n");
        printf("7: Tim kiem phan tu co trong mang\n");
        printf("8: Sap xep le truoc, chan sau\n");
        printf("9: Kiem tra mang co tang dan khong\n");
        printf("10: Thoat chuong trinh\n");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                for (int i=0;i<n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;

            case 2:
                count=0;
                for (int i=0;i<n;i++) {
                    if (PerfectNumber(arr[i])) {
                        count++;
                    }
                }
                printf("So luong so hoan hao trong mang la: %d\n", count);
                break;

            case 3:
                {
                    int secSmall=secSmallest(arr, n);
                    if (secSmall == -1) {
                        printf("Mang khong co gia tri nho thu 2.\n");
                    } else {
                        printf("Gia tri nho thu 2 trong mang la: %d\n", secSmall);
                    }
                }
                break;

            case 4:
                printf("Nhap vao vi tri muon them: ");
                scanf("%d", &index);
                if (index < 1 || index > n + 1) {
                    printf("Khong co vi tri nay\n");
                } else {
                    printf("Nhap gia tri muon them: ");
                    scanf("%d", &value);
                    for (int i=n; i>=index; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[index - 1] = value;
                    n++;
                }
                break;

            case 5:
                if (n==0) {
                    printf("Mang chua co phan tu.\n");
                } else {
                    printf("Nhap vao vi tri can xoa: ");
                    scanf("%d", &index);
                    while (index < 1 || index > n) {
                        printf("Khong co vi tri nay. Nhap lai vi tri can xoa: ");
                        scanf("%d", &index);
                    }
                    for (int i = index-1; i<n-1;i++) {
                        arr[i] = arr[i+1];
                    }
                    n--;
                }
                break;

            case 6:
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep tang dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 7:
                printf("Nhap so phan tu can tim: ");
                scanf("%d", &value);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d nam o vi tri %d.\n", value, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong thuoc ve mang nay.\n", value);
                }
                break;
        
           case 10:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");	
        }
    } while (choose!=11);

    return 0;
}
