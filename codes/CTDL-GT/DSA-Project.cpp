//Print all Possible Knight’s Tours in a chessboard
#include <iostream>

#define N 8

// Mảng lưu độ dời của quân Mã
int row[] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Hàm kiểm tra tọa độ hợp lệ
bool isValid(int x, int y) {
  return x >= 0 && y >= 0 && x < N && y < N;
}

// Hàm đệ quy tìm đường đi của quân Mã
void knightTour(int visited[N][N], int x, int y, int pos, int &solutionCount) {
  visited[x][y] = pos;
  if (pos >= N * N) {
    printf("Lan thu so %d\n", ++solutionCount);
    for (int i = 0; i < N; i++) { // Duyệt các hàng
      for (int j = 0; j < N; j++) // Duyệt các cột
        printf("%3d ", visited[N - 1 - i][j]); // In thứ tự bước đi
      printf("\n");
    }
    printf("\n");
    visited[x][y] = 0; // Quay lui
    return;
  }
// Duyệt các hướng đi
  for (int k = 0; k < 8; k++) {
    int newX = x + row[k], newY = y + col[k]; // Tính tọa độ mới
    if (isValid(newX, newY) && !visited[newX][newY]) // Nếu hợp lệ và chưa thăm
      knightTour(visited, newX, newY, pos + 1, solutionCount); // Đệ quy
  }
  visited[x][y] = 0; // Quay lui
}

int main() {
  int visited[N][N] = {0}, solutionCount = 0; // Khởi tạo mảng và biến
  knightTour(visited, 7, 1, 1, solutionCount); // Bắt đầu
  return 0;
}