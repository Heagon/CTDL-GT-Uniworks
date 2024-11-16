#include <stdio.h>

// Khai bao cau truc cho 1 node
struct Node {
    int gia_tri;
    struct Node* tiep_theo;
};

// Ham tao mot node moi
struct Node* tao_node(int gia_tri) {
    struct Node* node_moi = (struct Node*)malloc(sizeof(struct Node));
    node_moi->gia_tri = gia_tri;
    node_moi->tiep_theo = NULL;
    return node_moi;
}

// Ham them node vao cuoi danh sach
void them_cuoi(struct Node** dau, int gia_tri) {
    struct Node* node_moi = tao_node(gia_tri);
    if (*dau == NULL) {
        *dau = node_moi;
        return;
    }
    struct Node* tam = *dau;
    while (tam->tiep_theo != NULL) {
        tam = tam->tiep_theo;
    }
    tam->tiep_theo = node_moi;
}

// Ham in danh sach lien ket
void in_danh_sach(struct Node* dau) {
    struct Node* tam = dau;
    while (tam != NULL) {
        printf("%d ", tam->gia_tri);
        tam = tam->tiep_theo;
    }
    printf("\n");
}

// Ham xoa node o dau danh sach
void xoa_dau(struct Node** dau) {
    if (*dau == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    struct Node* tam = *dau;
    *dau = (*dau)->tiep_theo;
    free(tam);
}

// Ham xoa node o cuoi danh sach
void xoa_cuoi(struct Node** dau) {
    if (*dau == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    if ((*dau)->tiep_theo == NULL) {
        free(*dau);
        *dau = NULL;
        return;
    }
    struct Node* tam = *dau;
    while (tam->tiep_theo->tiep_theo != NULL) {
        tam = tam->tiep_theo;
    }
    free(tam->tiep_theo);
    tam->tiep_theo = NULL;
}

// Ham xoa node sau node cho truoc
void xoa_sau_node(struct Node* node) {
    if (node == NULL || node->tiep_theo == NULL) {
        printf("Khong co node de xoa sau\n");
        return;
    }
    struct Node* node_can_xoa = node->tiep_theo;
    node->tiep_theo = node_can_xoa->tiep_theo;
    free(node_can_xoa);
}

int main() {
    struct Node* dau = NULL;
    
    // Them cac node vao danh sach
    them_cuoi(&dau, 10);
    them_cuoi(&dau, 20);
    them_cuoi(&dau, 30);
    them_cuoi(&dau, 40);
    them_cuoi(&dau, 50);
    
    printf("Danh sach truoc khi xoa: \n");
    in_danh_sach(dau);

    // Xoa node o dau
    xoa_dau(&dau);
    printf("Danh sach sau khi xoa dau: \n");
    in_danh_sach(dau);

    // Xoa node o cuoi
    xoa_cuoi(&dau);
    printf("Danh sach sau khi xoa cuoi: \n");
    in_danh_sach(dau);

    // Xoa node sau node co gia tri 20
    struct Node* tam = dau;
    while (tam != NULL && tam->gia_tri != 20) {
        tam = tam->tiep_theo;
    }
    if (tam != NULL) {
        xoa_sau_node(tam);
        printf("Danh sach sau khi xoa node sau node co gia tri 20: \n");
        in_danh_sach(dau);
    } else {
        printf("Khong tim thay node co gia tri 20\n");
    }

    return 0;
}
