#include <stdio.h>

// Dinh nghia cau truc mot node luu tru mot tu
typedef struct NodeTu {
    char tu[100]; // Luu tru tu
    struct NodeTu* tiep_theo; // Con tro den node tiep theo
} NodeTu;

// Ham tao mot node moi
NodeTu* tao_node_tu(const char* tu) {
    static NodeTu node_pool[100]; // Bo nho tinh cho toi da 100 node
    static int node_index = 0;

    if (node_index >= 100) {
        printf("Bo nho cho node da day!\n");
        return NULL;
    }

    NodeTu* node_moi = &node_pool[node_index++];
    int i = 0;
    while (tu[i] != '\0' && i < 99) {
        node_moi->tu[i] = tu[i];
        i++;
    }
    node_moi->tu[i] = '\0';
    node_moi->tiep_theo = NULL;

    return node_moi;
}

// Ham chen tu vao cuoi danh sach lien ket
void chen_tu_cuoi(NodeTu** dau, const char* tu) {
    NodeTu* node_moi = tao_node_tu(tu);
    if (*dau == NULL) {
        *dau = node_moi;
    } else {
        NodeTu* hien_tai = *dau;
        while (hien_tai->tiep_theo != NULL) {
            hien_tai = hien_tai->tiep_theo;
        }
        hien_tai->tiep_theo = node_moi;
    }
}

// Ham dem so lan xuat hien cua tu trong danh sach lien ket
int dem_so_lan_xuat_hien(NodeTu* dau, const char* tu) {
    int dem = 0;
    NodeTu* hien_tai = dau;
    while (hien_tai != NULL) {
        int i = 0;
        while (hien_tai->tu[i] == tu[i] && tu[i] != '\0') {
            i++;
        }
        if (hien_tai->tu[i] == '\0' && tu[i] == '\0') {
            dem++;
        }
        hien_tai = hien_tai->tiep_theo;
    }
    return dem;
}

// Ham tim tu xuat hien nhieu nhat
void tim_tu_xuat_hien_nhieu_nhat(NodeTu* dau) {
    NodeTu* hien_tai = dau;
    int max_dem = 0;
    char tu_max[100];

    while (hien_tai != NULL) {
        int dem = dem_so_lan_xuat_hien(dau, hien_tai->tu);
        if (dem > max_dem) {
            max_dem = dem;
            int i = 0;
            while (hien_tai->tu[i] != '\0' && i < 99) {
                tu_max[i] = hien_tai->tu[i];
                i++;
            }
            tu_max[i] = '\0';
        }
        hien_tai = hien_tai->tiep_theo;
    }

    printf("Tu xuat hien nhieu nhat: %s (%d lan)\n", tu_max, max_dem);
}

// Ham loai bo tu lay (cac tu giong nhau lien ke)
void loai_bo_tu_lay(NodeTu** dau) {
    NodeTu* hien_tai = *dau;
    while (hien_tai != NULL && hien_tai->tiep_theo != NULL) {
        int i = 0;
        while (hien_tai->tu[i] == hien_tai->tiep_theo->tu[i] && hien_tai->tu[i] != '\0') {
            i++;
        }
        if (hien_tai->tu[i] == '\0') { // Cac tu giong nhau hoan toan
            hien_tai->tiep_theo = hien_tai->tiep_theo->tiep_theo;
        } else {
            hien_tai = hien_tai->tiep_theo;
        }
    }
}

// Ham dem so tu vung trong cau
int dem_so_tu(NodeTu* dau) {
    int dem = 0;
    NodeTu* hien_tai = dau;
    while (hien_tai != NULL) {
        dem++;
        hien_tai = hien_tai->tiep_theo;
    }
    return dem;
}

// Ham in cac tu trong danh sach lien ket
void in_danh_sach(NodeTu* dau) {
    NodeTu* hien_tai = dau;
    while (hien_tai != NULL) {
        printf("%s ", hien_tai->tu);
        hien_tai = hien_tai->tiep_theo;
    }
    printf("\n");
}

int main() {
    NodeTu* cau = NULL;

    // Chen cac tu vao danh sach lien ket (gia su cau la "hoa hong xanh xanh rat dep")
    chen_tu_cuoi(&cau, "hoa");
    chen_tu_cuoi(&cau, "hong");
    chen_tu_cuoi(&cau, "xanh");
    chen_tu_cuoi(&cau, "xanh");
    chen_tu_cuoi(&cau, "rat");
    chen_tu_cuoi(&cau, "dep");

    // In danh sach tu
    printf("Danh sach tu ban dau: \n");
    in_danh_sach(cau);

    // Tim tu xuat hien nhieu nhat
    tim_tu_xuat_hien_nhieu_nhat(cau);

    // Loai bo tu lay
    loai_bo_tu_lay(&cau);
    printf("Danh sach sau khi loai bo tu lay: \n");
    in_danh_sach(cau);

    // Dem so tu vung
    int so_tu = dem_so_tu(cau);
    printf("So tu vung trong cau: %d\n", so_tu);

    return 0;
}
