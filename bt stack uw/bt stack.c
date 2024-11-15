#include <stdio.h>
#include <stdlib.h>

typedef struct go {
    char loai_go[50];
    int kich_thuoc;
    int tuoi_go;
    struct go *tiep;
} Go;

Go* tao_go(char* loai_go, int kich_thuoc, int tuoi_go) {
    Go* go_moi = (Go*)malloc(sizeof(Go));
    int i;
    for (i = 0; loai_go[i] != '\0'; i++) {
        go_moi->loai_go[i] = loai_go[i];
    }
    go_moi->loai_go[i] = '\0';
    go_moi->kich_thuoc = kich_thuoc;
    go_moi->tuoi_go = tuoi_go;
    go_moi->tiep = NULL;
    return go_moi;
}

void day_go(Go** top, char* loai_go, int kich_thuoc, int tuoi_go) {
    Go* go_moi = tao_go(loai_go, kich_thuoc, tuoi_go);
    go_moi->tiep = *top;
    *top = go_moi;
}

void in_danh_sach_go_theo_tuoi(Go* top) {
    Go* current = top;
    int da_in[100];
    int so_tuoi_da_in = 0;

    while (current != NULL) {
        int tuoi_go_hien_tai = current->tuoi_go;
        int da_duyet = 0;
        for (int i = 0; i < so_tuoi_da_in; i++) {
            if (da_in[i] == tuoi_go_hien_tai) {
                da_duyet = 1;
                break;
            }
        }
        if (!da_duyet) {
            printf("Tuoi go: %d nam\n", tuoi_go_hien_tai);
            int dem = 1;
            Go* temp = top;
            while (temp != NULL) {
                if (temp->tuoi_go == tuoi_go_hien_tai) {
                    printf("%d. -Loai go: %s\n   -Kich thuoc: %dm\n", dem++, temp->loai_go, temp->kich_thuoc);
                }
                temp = temp->tiep;
            }
            da_in[so_tuoi_da_in++] = tuoi_go_hien_tai;
        }
        current = current->tiep;
    }
}

void nhap_go(Go** top) {
    char loai_go[50];
    int kich_thuoc, tuoi_go;
    printf("Nhap loai go: ");
    scanf("%s", loai_go);
    printf("Nhap kich thuoc: ");
    scanf("%d", &kich_thuoc);
    printf("Nhap tuoi go: ");
    scanf("%d", &tuoi_go);
    day_go(top, loai_go, kich_thuoc, tuoi_go);
}

int main() {
    Go* top = NULL;
    int chon;
    do {
        printf("1. Nhap go\n");
        printf("2. In danh sach go cung tuoi\n");
        printf("3. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);
        if (chon == 1) {
            nhap_go(&top);
        } else if (chon == 2) {
            in_danh_sach_go_theo_tuoi(top);
        }
    } while (chon != 3);
    return 0;
}