#include <iostream>

using namespace std;

void in_vector(const char* vec, int size) {
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void in_danh_sach_ke(const char* cac_dinh, const char** danh_sach_ke, int so_luong_dinh) {
    for (int i = 0; i < so_luong_dinh; ++i) {
        cout << "Dinh " << cac_dinh[i] << ": ";
        int size = 0;
        while(danh_sach_ke[i][size] != '\0') {
            size++;
        }
        in_vector(danh_sach_ke[i], size);
    }
}

class Graph {
public:
    char** danh_sach_ke;
    char* cac_dinh;
    int so_luong_dinh;

    Graph(const int* ma_tran_ke, const char* cac_dinh, int so_luong_dinh) {
        this->so_luong_dinh = so_luong_dinh;
        this->cac_dinh = new char[so_luong_dinh];
        for(int i=0; i<so_luong_dinh; ++i) {
            this->cac_dinh[i] = cac_dinh[i];
        }
        this->danh_sach_ke = new char*[so_luong_dinh];
        for(int i=0; i < so_luong_dinh; i++) {
            this->danh_sach_ke[i] = new char[so_luong_dinh+1];
            int index = 0;
            for(int j=0; j<so_luong_dinh; ++j) {
                if(ma_tran_ke[i*so_luong_dinh+j] == 1) {
                    this->danh_sach_ke[i][index] = cac_dinh[j];
                    index++;
                }
            }
            this->danh_sach_ke[i][index] = '\0';
        }
    }

    ~Graph() {
        for(int i = 0; i < so_luong_dinh; ++i) {
            delete[] danh_sach_ke[i];
        }
        delete[] danh_sach_ke;
        delete[] cac_dinh;
    }

    void in_do_thi() {
        in_danh_sach_ke(cac_dinh, (const char**)danh_sach_ke, so_luong_dinh);
    }

   void bfs(char bat_dau) {
        bool *da_tham = new bool[so_luong_dinh];
        for (int i = 0; i < so_luong_dinh; ++i) {
            da_tham[i] = false;
        }

        char* hang_doi = new char[so_luong_dinh];
        int front = 0, rear = 0;
        char *bfs_thu_tu = new char[so_luong_dinh];
        int thu_tu_index = 0;
        int start_index = -1;
        for(int i = 0; i < so_luong_dinh; ++i) {
            if(cac_dinh[i] == bat_dau) {
                start_index = i;
                break;
            }
        }
        if(start_index == -1) {
            cout << "Dinh bat dau khong hop le!" << endl;
            return;
        }
        da_tham[start_index] = true;
        hang_doi[rear++] = cac_dinh[start_index];

         while(front < rear) {
            char dinh = hang_doi[front++];
             bfs_thu_tu[thu_tu_index++] = dinh;
             
            int dinh_index = -1;
            for(int i=0; i<so_luong_dinh; ++i) {
                if(cac_dinh[i] == dinh) {
                    dinh_index = i;
                     break;
                }
            }
         
             for(int ke_index = 0; ke_index < so_luong_dinh; ++ke_index) {
                bool is_adj = false;
                int length = 0;
                 while(danh_sach_ke[dinh_index][length] != '\0'){
                     if(cac_dinh[ke_index] == danh_sach_ke[dinh_index][length])
                      {
                         is_adj = true;
                         break;
                     }
                    length++;
                 }
                 if(is_adj && !da_tham[ke_index]) {
                    da_tham[ke_index] = true;
                    hang_doi[rear++] = cac_dinh[ke_index];
                 }
            }
        }
        cout << "Thu tu BFS: ";
        in_vector(bfs_thu_tu, thu_tu_index);
        delete[] da_tham;
        delete[] hang_doi;
        delete[] bfs_thu_tu;
    }


    void dfs(char bat_dau) {
        bool *da_tham = new bool[so_luong_dinh];
        for (int i = 0; i < so_luong_dinh; ++i) {
            da_tham[i] = false;
        }

        char* ngan_xep = new char[so_luong_dinh];
        int top = -1;
        char* dfs_thu_tu = new char[so_luong_dinh];
        int thu_tu_index = 0;

        int start_index = -1;
        for(int i = 0; i < so_luong_dinh; ++i) {
            if(cac_dinh[i] == bat_dau) {
                start_index = i;
                break;
            }
        }
        if(start_index == -1) {
            cout << "Dinh bat dau khong hop le!" << endl;
            return;
        }
        ngan_xep[++top] = cac_dinh[start_index];
        
        while(top != -1) {
           char dinh = ngan_xep[top--];
          
           int dinh_index = -1;
            for(int i=0; i<so_luong_dinh; ++i) {
                if(cac_dinh[i] == dinh) {
                    dinh_index = i;
                    break;
                }
            }
            
            if (!da_tham[dinh_index]) {
                da_tham[dinh_index] = true;
                dfs_thu_tu[thu_tu_index++] = dinh;

                 for(int ke_index = so_luong_dinh - 1; ke_index >= 0; --ke_index) {
                    bool is_adj = false;
                    int length = 0;
                     while(danh_sach_ke[dinh_index][length] != '\0') {
                          if(cac_dinh[ke_index] == danh_sach_ke[dinh_index][length]) {
                              is_adj = true;
                              break;
                          }
                           length++;
                    }
                      if(is_adj) {
                       ngan_xep[++top] = cac_dinh[ke_index];
                      }

                 }
             }
        }
        cout << "Thu tu DFS: ";
        in_vector(dfs_thu_tu, thu_tu_index);
        delete[] da_tham;
        delete[] ngan_xep;
        delete[] dfs_thu_tu;
    }
};


int main() {
    char cac_dinh[] = {'a', 'b', 'c', 'd', 'e', 'g', 'h'};
    int ma_tran_ke[] = {
        0, 1, 0, 1, 1, 0, 1,
        0, 0, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 1,
        1, 0, 1, 0, 0, 1, 1,
        0, 1, 0, 1, 0, 1, 1,
        1, 1, 1, 0, 1, 0, 1,
        0, 0, 0, 0, 1, 0, 0
    };
    int so_luong_dinh = 7;

    Graph do_thi(ma_tran_ke, cac_dinh, so_luong_dinh);
    cout << "Do thi:" << endl;
    do_thi.in_do_thi();

    cout << endl;

    cout << "Duyet do thi:" << endl;
    do_thi.bfs('a');
    do_thi.dfs('a');

    return 0;
}